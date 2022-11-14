/*
Question:-
Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
Note: It is guaranteed that the node exists in the tree.

Example 1:-
Input:

k = 1
node = 3

      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.

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
Node *solve(Node *root, int &k, int node)
{
    // Base Case
    if (root == NULL)
    {
        return NULL;
    }

    // first find the node.
    if (root->data == node)
    {
        return root;
    }

    // make a recursive call on left and right.
    Node *leftAns = solve(root->left, k, node);
    Node *rightAns = solve(root->right, k, node);

    // Backtracking step.

    // if any one of any is successfull in finding the node,
    // in that case decrement the k and check if  k == 0, it means the current node is our answer.
    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            // lock the answer.
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{

    Node *ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
    {
        return -1;
    }
    else
        return ans->data;
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

    int k = 2;
    int node = 5;
    cout<<kthAncestor(root, k, node)<<endl;
}