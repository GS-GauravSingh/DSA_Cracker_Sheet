/*
Question:-
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.

If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal.

For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \
                 10       14

For the above tree the output should be 5 10 4 14 25.

Approach:-

<0> = 20
<-1> = 8
<1> = 22
<-2> = 5


<0> = 3 // remove old value of 0 (which is 20).
<0> = 4 // remove old value of 0 (which is 3).

<2> = 25

<-1> = 10 // remove old value of -1 (which is 8).

<1> = 14 // remove old value of  1 (which is 22).

Now print all hd's in sorted order,

hd :- -2, -1, 0 ,1, 2
ans:-  5, 10, 4, 14, 25


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/* Function to return a list of nodes visible from the bottom view */
/* from left to right in Binary Tree. */
vector<int> bottomView(Node *root)
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

        // at any particular hd, if value is exist, we will rewrite it.
        // if value doesn't exist, then we will store it.
        mpp[hd] = frontNode->data;

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
    vector<int> ans = bottomView(root);
    print(ans);
}