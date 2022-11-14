#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Time Complexity:- O(N)
Space Complexity:- O(H), H is the height of the tree.
*/

/* Function to return the maximum sum of non-adjacent nodes. */

// 1st block of pair = including node at current level.
// 2nd block of pair = excluding node at current level.
pair<int, int> solve(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return {0, 0};
    }

    // Recursive case
    pair<int, int> leftAns = solve(root->left);
    pair<int, int> rightAns = solve(root->right);

    pair<int, int> res;

    // if your are including the current node,
    // then you have to exclude the child nodes of current node.
    res.first = root->data + leftAns.second + rightAns.second;

    // if your are excluding the current node,
    // then you have to include the child nodes of current node.
    res.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

    return res;
}
int getMaxSum(Node *root)
{
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main()
{
    /*
   Exmaple TestCases:-

   Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , Height = 3.
   view:-                      1                           level 0
                       3               5                   level 1
                   7      11       17      -1              level 2
               -1  -1  -1  -1   -1   -1                    level 3


   Ex 2:-  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1, Height = 4.
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

    cout<<getMaxSum(root);
}