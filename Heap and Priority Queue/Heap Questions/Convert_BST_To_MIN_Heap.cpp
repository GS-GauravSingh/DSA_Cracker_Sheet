#include <bits/stdc++.h>
#include "../../Binary Search Tree/BST Implementation/BST_Implementation.h"
using namespace std;

/*
Time Complexity:- O(N) 
Space Complexity:- O(N)   
*/


/* Inorder Traversal */
void InOrderTraversal(Node *root, vector<int> &inorder)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Recursive Case
    InOrderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    InOrderTraversal(root->right, inorder);
}

/* PreOrder Traversal */
void PreOrderTraversal(Node *root, int &i, vector<int> &inorder)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Recursive Case
    // Replace Value
    root->data = inorder[i++];
    PreOrderTraversal(root->left, i, inorder);
    PreOrderTraversal(root->right, i, inorder);
}

void BST_To_MIN_Heap(Node *&root)
{
    // Given a binary search tree (BST) which is also a complete binary tree.
    // The problem is to convert the given BST into a Min Heap.

    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Step 1:- store the inorder traversal of BST into vector.
    // as we know inorder traversal of BST came out in a sorted order.
    vector<int> inorder;
    InOrderTraversal(root, inorder);

    // Step 2:- do the preorder traversal of BST the replace the value with our inorder vector.
    int i = 0;
    PreOrderTraversal(root, i, inorder);
}
int main()
{

    /*
    Example Testcases:- 4 2 6 1 3 5 7 -1
    */
    BinarySearchTree bst;
    Node *root = NULL;
    bst.takeInput(root);
    cout << "Before Conversion:-\n";
    bst.LevelOrderTraversal(root);

    cout << "After Conversion:-\n";
    BST_To_MIN_Heap(root);
    bst.LevelOrderTraversal(root);
}