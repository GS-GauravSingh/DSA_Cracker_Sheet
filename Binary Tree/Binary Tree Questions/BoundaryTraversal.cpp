/*
Question:-
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:

Example 1:

Input:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
      / \
     8   9

Output: 1 2 4 8 9 6 7 3


Approach:-
step 1:- print left nodes, excluding leaf nodes.
step 2:- print leaf nodes, from left to right.
step 3:- print right nodes in reverse order.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary.

Time Complexity:- O(n)
Space Complexity:- O(h), h is the height of the tree.
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/* Traversing Left Nodes, excluding leaf nodes */
void traverseLeft(Node *root, vector<int> &ans)
{
    // Base Case
    // If root == NULL, return from here and if it is a leaf node then also return.
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    // else, print/store left part.
    ans.push_back(root->data);

    // and move to left, if left exist's.
    if (root->left != NULL)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        // if left doesn't exist, only then move to right.
        traverseLeft(root->right, ans);
    }
}

/* Traversing Leaf Nodes, from left to right */
void traverseLeaf(Node *root, vector<int> &ans)
{
    // Base Case
    // If root == NULL, return from here.
    if (root == NULL)
    {
        return;
    }

    // if it is a leaf node then store it.
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    // move left, right.
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}


/* Traversing Right part, in reverse order */
void traverseRight(Node *root, vector<int> &ans)
{
    // Base Case
    // If root == NULL, return from here and if it is a leaf node then also return.
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    // move to right, if right exist's.
    if (root->right != NULL)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        // if right doesn't exist, only then move to left.
        traverseRight(root->left, ans);
    }

    // Backtracking step, store the data.
    ans.push_back(root->data);
}


vector<int> boundary(Node *root)
{
    // Base Case
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    // push root -> data, because at first we have to print root -> data.
    ans.push_back(root->data);

    // store left part
    traverseLeft(root->left, ans);

    // store leaf Nodes of left subtree.
    traverseLeaf(root->left, ans);
    // store leaf Nodes of right subtree.
    traverseLeaf(root->right, ans);

    // store right part.
    traverseRight(root->right, ans);

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

    // Boundary traversal
    vector<int> ans;
    ans = boundary(root);
    print(ans);
}