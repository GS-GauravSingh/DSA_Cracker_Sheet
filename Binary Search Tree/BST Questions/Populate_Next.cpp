/*
Given a Binary Tree, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.

Example 1:

Input:
           10
       /  \
      8    12
     /
    3


Output: 3->8 8->10 10->12 12->-1



Approach:- Using Reverse Inorder Traversal

Traverse the given tree in reverse inorder traversal and keep track of previously visited node. When a node is being visited, assign a previously visited node as next.
*/
#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;

/*
Time Complexity:- O(n)
Space Complexity:- O(n)
*/


void solve(Node *&root, Node *&nextNode)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Recursive Case, Reverse Inorder Traversal

    // make a recursive cal, for right part.
    solve(root->right, nextNode);

    // process root node (make connections). 
    // root->next = nextNode; // next pointer is not defined in node structure of BST implementation.
    nextNode = root;

    // make a recursive cal, for left part.
    solve(root->left, nextNode);
}

void populateNext(Node *root)
{
    Node *nextNode = NULL;
    solve(root, nextNode);
}

int main()
{
    /*
    Ex 1:- 21 10 5 15 50 40 60 35 70 -1
    Ex 2:- 50 20 70 10 30 90 110 -1
    */

    Node *root = NULL;
    BinarySearchTree bst;
    bst.takeInput(root);

}