/*
Question:-
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.

If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9
Output:
4 2 1 5 6 3 8 7 9

Approach:-
Suppose there is a number line.

          -2  -1   0    1   2   3
                   1                                level 0
                 /   \
               2       3                            level 1
             /   \   /   \
           4      5 6      7                        level 2
                      \      \
                       8      9                     level 3

Now, when youn traverse the tree using level order traversal.

for level 0 and for number 0 on number line the answer is = 1

for level 1 and for number -1 on number line the answer is = 2
for level 1 and for number 1 on number line the answer is = 3

for level 2 and for number -1 on number line the answer is = 4
for level 2 and for number 0 on number line the answer is = 5, 6
for level 2 and for number 2 on number line the answer is = 7

for level 3 and for number 1 on number line the answer is = 8
for level 3 and for number 3 on number line the answer is = 8

Summarize:- (level, point on number line) = list of data.

(level 0, number 0) = 1,5,6
(level 1, number -1) = 2
(level 1, number 1) = 3
(level 2, number -2) = 4
(level 2, number 2) = 7
(level 3, number 1) = 8
(level 3, number 3) = 9

Now, print all vector in single line in sorted order(sort according to number line, means first -2, -1, 0 ,1, 2, 3, and so on.)

-2 = 4
-1 = 2
0 = 1,5,6
1 = 3,8
2 = 7
3 = 9

Answer = {4,2,1,5,6,3,8,7,9}
our answer is same as Output:- 4 2 1 5 6 3 8 7 9

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

vector<int> verticalOrder(Node *root)
{
    // map to store horizontal distance correspond to level-wise nodes.
    map<int, map<int, vector<int>>> nodes;

    // queue to store node correspond to horizontal distance, level.
    queue<pair<Node *, pair<int, int>>> q;

    // vector to store answer.
    vector<int> ans;

    // Base Case
    if (root == NULL)
    {
        return ans;
    }

    // initially horizontal distance is 0 and level is also 0.
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        // get the front node.
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();

        // seperate the 3 values.
        Node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        // push data
        nodes[hd][lvl].push_back(frontNode->data);

        // push left and right child.
        if (frontNode->left != NULL)
        {
            // while going toward left horizontal distance is decreased and level in increased.
            q.push({frontNode->left, {hd - 1, lvl + 1}});
        }
        if (frontNode->right != NULL)
        {
            // while going toward right horizontal distance is increased and level in also increased.
            q.push({frontNode->right, {hd + 1, lvl + 1}});
        }
    }

    // store answer.
    for (auto i : nodes)
    {
        // i =  map<int, map<int, vector<int>>>;
        // i.second =    map<int, vector<int>>;
        for (auto j : i.second)
        {
            // j = map<int, vector<int>>
            for (auto k : j.second)
            {
                // k = vector<int>
                ans.push_back(k);
            }
        }
    }
    return ans;
}

/* Method to print vector */
void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    /*
 Exmaple TestCases:-

 Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 18 19 -1 -1 -1 -1 -1,
 view:-                      1                           level 0
                     3               5                   level 1
                 7      11       17      -1              level 2
             -1  -1  -1  -1   18   -1                    level 3
                            19   -1
                         -1   -1


 Ex 2:-  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1,
 view:-                          1                        level 0
                     2                   3                level 1
                 4       5           -1      6            level 2
              -1  -1   7   -1             -1   -1         level 3
                    -1  -1                                level 4

 */

    // Building tree
    Node *root = NULL;
    BinaryTree bt;
    bt.BuildTree_PreOrder(root);

    // Vertical Traversal
    vector<int> ans = verticalOrder(root);
    print(ans);
}