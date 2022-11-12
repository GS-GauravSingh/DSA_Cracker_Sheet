/*
Question:-
Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree)
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/* Function to return a list of nodes visible from the right view */
void solve(Node *root, vector<int> &ans, int lvl)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // how this condition works,
    // for level 0, ans.size() = 0, we push data.
    // for level 1, ans.size() = 1, we push data.
    // and so on.
    if (lvl == ans.size())
    {
        ans.push_back(root->data);
    }

    // make a recursive call, first on right side then left side.
    solve(root->right, ans, lvl + 1);
    solve(root->left, ans, lvl + 1);
}

// Function to return list containing elements of right view of binary tree.
vector<int> rightView(Node *root)
{
    // Your Code here
    vector<int> ans;
    solve(root, ans, 0);
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
    vector<int> ans = rightView(root);
    print(ans);
}