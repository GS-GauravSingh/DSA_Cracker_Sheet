/*
Question:-
find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Example 1:

Input:
        4
       / \
      2   5
     / \ / \
    7  1 2  3
      /
     6
Output: 13

Explanation:
        4
       / \
      2   5
     / \ / \
    7  1 2  3
      /
     6

The highlighted nodes (4, 2, 1, 6) above are
part of the longest root to leaf path having

sum = (4 + 2 + 1 + 6) = 13

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Time Complexity:- O(N)
Space Complexity:- O(N)
*/

void solve(Node *root, int sum, int &maxSum, int len, int &maxLen)
{
    // Base Case
    if (root == NULL)
    {
        // if root == NULL, it means you reach the end of particular path in a tree.
        // compare length.
        if (len > maxLen)
        {
            // update maxLen and maxSum.
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            // If two or more paths compete for the longest path,
            // then the path having maximum sum of nodes is being considered.

            // update maxSum
            maxSum = max(maxSum, sum);
        }

        return;
    }

    // Recursive Case
    // add root -> data into sum;
    sum = sum + root->data;

    // make a recursive call for root -> left and root -> right and increment the length.
    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
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

    cout<<sumOfLongRootToLeafPath(root)<<endl;
}