#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Time Complexity:- O(n), where n is number of nodes.
Space Complexity:- O(n), function call stack size.
*/

int solve(Node *root, int &ans)
{
    // Base Case
    if (root == NULL)
        return 0;

    // Scalculate sum.
    int currSum = root->data + solve(root->left, ans) + solve(root->right, ans);

    // Update answer.
    ans = max(ans, currSum);

    return currSum;
}

// Function to find largest subtree sum.
int findLargestSubtreeSum(Node *root)
{
    // Base Case
    if (root == NULL)
        return 0;

    // Variable to store ans.
    int ans = INT_MIN;

    solve(root, ans);
}

int main()
{
    /*
    Exmaple TestCases:-

    Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 ,
    view:-                      1                           level 0
                        3               5                   level 1
                    7      11       17      -1              level 2
                -1  -1  -1  -1   -1   -1                    level 3


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

    cout<<findLargestSubtreeSum(root);
}