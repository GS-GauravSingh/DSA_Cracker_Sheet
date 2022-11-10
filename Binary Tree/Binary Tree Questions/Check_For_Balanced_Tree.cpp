/*
Question:-

Given a binary tree, find if it is height balanced or not.
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /
   10
  /
5
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

// Approach 1: code
//    Time Complexity: O(n^2)
//    Space Complexity: O(n)

// Function to for calculating height of the tree..
int height(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    // Recursive Case

    // calculating the height of left subtree.
    int left = height(root->left);

    // calculating the height of right subtree.
    int right = height(root->right);

    // Overall height = max(left, right) + 1; // +1 for height of root node.
    int height = max(left, right) + 1;

    // return height;
    return height;
}

// Function to check for balanced tree.
bool isBalanced(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        // Null is balanced.
        return true;
    }

    // Recursive Case

    // chekck if left subtree is balanced or not.
    bool left = isBalanced(root->left);

    // chekck if right subtree is balanced or not.
    bool right = isBalanced(root->right);

    // if the diff of heights left and right <= 1,means tree is balanced else not.
    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    // if all 3 conditions are true, it means tree is balanced
    if (left && right && diff)
    {
        return true;
    }

    // from above 3 conditions, if any one of the become false it means tree is not balanced.
    return false;
}

// Approach 2: code
//    Time Complexity: O(n)
//    Space Complexity: O(n)

// first block represents tree blanced or not.
// second block represents height of tree.
pair<bool, int> isBalanced_Fast(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        // Null is balanced, and height = 0.
        return {true, 0};
    }

    // Recursive Case

    // check if left subtree is balanced or not.
    pair<bool,int> left = isBalanced_Fast(root -> left);

    // check if right subtree is balanced or not.
    pair<bool,int> right = isBalanced_Fast(root -> right);


    bool leftAns = left.first;
    bool rightAns = right.first;
    // if the diff of heights left and right <= 1,means tree is balanced else not.
    bool diff = abs(left.second - right.second) <= 1;

    // pair to store ans.
    pair<bool, int> ans;

    // height calculation
    ans.second = max(left.second, right.second) + 1;

    // if all 3 conditions are true, it means tree is balanced
    if (leftAns && rightAns && diff)
    {
        ans.first =  true;
    }
    // from above 3 conditions, if any one of the become false it means tree is not balanced.
    else{
        ans.first = false;
    }

    return ans;
    
}

int main()
{
    /*
   Exmaple TestCases:-

   Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 18 19 -1 -1 -1 -1 -1, Not Balanced 
   view:-                      1                           level 0
                       3               5                   level 1
                   7      11       17      -1              level 2
               -1  -1  -1  -1   18   -1                    level 3
                              19   -1
                           -1   -1


   Ex 2:-  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1, Balanced
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

    cout<<isBalanced(root)<<endl;
    cout<<isBalanced_Fast(root).first;
}