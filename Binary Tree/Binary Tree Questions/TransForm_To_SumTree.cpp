/*
Question:-
Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

Example 1:

Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Time Comlexity:- O(n)
Space Comlexity:- O(height of the tree)
*/

// creating previous and head pointer for DLL.

// Convert a given tree to a tree where every node contains sum of values of
// nodes in left and right subtrees in the original tree
int transformToSumTree(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    // if it is a leaf node.
    if (root->left == NULL && root->right == NULL)
    {
        // store leafnode -> data and then set it to 0;
        int data = root->data;

        // set leafnode -> data = 0;
        root->data = 0;

        // return stored data.
        return data;
    }

    // Recursive Case,

    // make a recursive call on left.
    int left = transformToSumTree(root->left);

    // make a recursive call on right.
    int right = transformToSumTree(root->right);

    // process root node.
    int rootData = root->data;
    root->data = left + right;

    // return rootData + root -> data.
    return (root->data + rootData);
}

void toSumTree(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    transformToSumTree(root);
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

    toSumTree(root);
    bt.PreOrder_Traversal(root);
}