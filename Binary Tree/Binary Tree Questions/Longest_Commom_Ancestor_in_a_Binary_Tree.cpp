/*
Question:-
Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

Example 1:

Input:
n1 = 2 , n2 = 3
       1
      / \
     2   3
Output: 1

Explanation:
LCA of 2 and 3 is 1.
Example 2:

Input:
n1 = 3 , n2 = 4
           5
          /
         2
        / \
       3   4
Output: 2

Explanation:
LCA of 3 and 4 is 2.

Expected Time Complexity:- O(N).
Expected Auxiliary Space:- O(Height of Tree).
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Time Complexity:- O(N)
Space Complexity:- O(h), h is the height of the tree.
*/

/*Function to return the lowest common ancestor in a Binary Tree.*/
Node *lca(Node *root, int n1, int n2)
{
    // Base Case
    // if root == NULL, simply return NULL.
    if (root == NULL)
    {
        return NULL;
    }
    // find n1 and n2.
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    // Recursive case
    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    // for current root, if leftAns and rightAns both != NULL, it means this root is our lca for n1 and n2.
    // return root.
    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        // if leftAns is successfull in finding n1 or n2, in that case simply return leftAns;
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        // if rightAns is successfull in finding n1 or n2, in that case simply return rightAns;
        return rightAns;
    }
    else
    {
        // if leftAns and rightAns both are not successfull in finding n1 or n2, in that case simply return NULL;
        return NULL;
    }
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

    int n1 = 7,n2 = 17;
    Node* ans = lca(root, n1, n2);
    cout<<ans->data<<endl;

}