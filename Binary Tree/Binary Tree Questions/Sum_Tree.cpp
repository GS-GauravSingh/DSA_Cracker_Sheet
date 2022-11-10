/*
Question:-
Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.



Example 1:

Input:
    3
  /   \
 1     2

Output: 1

Explanation:
The sum of left subtree and right subtree is
1 + 2 = 3, which is the value of the root node.
Therefore,the given binary tree is a sum tree.

*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

// Time Complexity:- O(n)
// Space Complexity:- O(h), h is the height of the tree.
pair<bool, int> isSumTreeFast(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return {true, 0};
    }
    // No need to check leaf nodes.
    if (root->left == NULL && root->right == NULL)
    {
        return {true, root->data}; // sum is equal to leaf node -> data.
    }

    // Recursive Case

    // check if left subtree is sumtree or not.
    pair<bool, int> left = isSumTreeFast(root->left);

    // check if right subtree is sumtree or not.
    pair<bool, int> right = isSumTreeFast(root->right);

    // getting the answer of left and right subtree.
    bool isLeftSumtree = left.first;
    bool isRightSumtree = right.first;

    // evaluate the given condition.
    // if sum of left subtree + sum of right subtree == root -> data
    bool compareSum = root->data == left.second + right.second;

    // pair to store ans.
    pair<bool, int> ans;

    // if all 3 conditions are ture, means tree is sum tree.
    if (isLeftSumtree && isRightSumtree && compareSum)
    {
        ans.first = true;
        ans.second = left.second + right.second + root->data;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

bool isSumTree(Node *root)
{
    return isSumTreeFast(root).first;
}

int main()
{
    /*
  Exmaple TestCases:-

  Ex 1:- 3 2 -1 -1 1 -1 -1, sumtree.
  view:-                      3                           level 0
                      2               1                   level 1
                 -1      -1       -1      -1              level 2



  Ex 2:- 10 20 10 -1 -1 10 -1 -1 30 -1 -1, not sumtree.
  view:-                          10                        level 0
                      20                   30               level 1
                  10       10          -1      -1         level 2
               -1  -1   -1   -1                             level 3
 

  */
    // Building tree
    Node *root = NULL;
    BinaryTree bt;
    bt.BuildTree_PreOrder(root);

    cout << isSumTree(root);
}