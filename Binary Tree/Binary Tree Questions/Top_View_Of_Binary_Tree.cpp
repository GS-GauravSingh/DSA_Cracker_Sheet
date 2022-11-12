/*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7

Note: Return nodes from leftmost node to rightmost node.

Exmaple 1:-
Input:

       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100

Approach:- Approach same as vertical order traversal,

<level 0, number 0 on no. line> = 10

<level 1, number -1 on no. line> = 20
<level 1, number  1 on no. line> = 30

<level 2, number  -2 on no. line> = 40
<level 2, number   0 on no. line> = 60, 90, but at <level 0 and no. 0> pe phele hi ek value aa chuki hai (10) toh agar hum top se dekhenge toh 60 and 90 jo hai ye 10 ke niche aayenge like this,
10
60
90

toh hume upar se sirf 10 hi dikhayi dega toh hum 60 and 90 ko ignore karenge.

<level 2, number  2 on no. line> = 100

Note:- so, we need only one value at any particular horizontal distance.
So we need a map to store 1 to 1 mappinp of hd -> Node.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N).
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/* Function to return a list of nodes visible from the top view */
/* from left to right in Binary Tree. */
vector<int> topView(Node *root)
{
    // vector to store final answer.
    vector<int> ans;
    // Base case
    if (root == NULL)
    {
        return ans;
    }

    // we need 1 to 1 mapping of horizontal distance(hd) -> Node
    map<int, int> mpp;

    // queue of Node*, hd.
    queue<pair<Node *, int>> q;

    // push data into queue.
    // initially horizontal distance is 0.
    q.push({root, 0});

    while (!q.empty())
    {

        // getting the value form queue;
        pair<Node *, int> temp = q.front();
        q.pop(); // pop it.

        // extract the hd, frontNode from the above value.
        Node *frontNode = temp.first;
        int hd = temp.second;

        // At any particular hd, if value doesn't exists in map only then we have to insert the value.
        // if value already exist's in the map, in that case do nothing.
        if (mpp.find(hd) == mpp.end())
        {
            mpp[hd] = frontNode->data;
        }

        // push left and right child.
        if (frontNode->left != NULL)
        {
            q.push({frontNode->left, hd - 1});
        }
        if (frontNode->right != NULL)
        {
            q.push({frontNode->right, hd + 1});
        }
    }

    // extract the values from map and store it in our answer vector.
    for (auto i : mpp)
    {
        ans.push_back(i.second);
    }

    // return ans;
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

    // Top View
    vector<int> ans = topView(root);
    print(ans);
}