#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;

// Recursive Apporach,
// Time Complexity:- O(log n), in worst case (skew tree) O(n).
// Space Complexity:- O(heigh of the tree)
bool searchInBST(Node *root, int x)
{
    // Base Case
    if (root == NULL)
    {
        return false;
    }

    // Recursive Case

    // Simple Binary search on BST.
    if (root->data == x)
    {
        return true;
    }
    else if (x < root->data)
    {
        // if x < root -> data, search for x in left subtree.
        searchInBST(root->left, x);
    }
    else
    {
        // if x > root -> data, search for x in right subtree.
        searchInBST(root->right, x);
    }
}

// Iterative Apporach,
// Time Complexity:- O(log n), in worst case (skew tree) O(n).
// Space Complexity:- O(1)
bool searchInBST_Iterative(Node *root, int x)
{
    // Base Case
    if (root == NULL)
    {
        return false;
    }

    // Simple Binary search on BST.
    Node *curr = root;
    while (curr != NULL)
    {

        if (curr->data == x)
        {
            return true;
        }
        else if (x < curr->data)
        {
            // if x < curr -> data, search for x in left subtree.
            curr = curr->left;
        }
        else
        {
            // if x > curr -> data, search for x in right subtree.
            curr = curr->right;
        }
    }
    return false;
}

int main()
{
    /*
    Example TestCases:-

    Ex 1:- 10 8 7 21 27 5 4 3 -1
    Ex 2:- 21 10 5 15 50 40 60 35 70 -1

    */

    Node *root = NULL;
    BinarySearchTree bst;
    bst.takeInput(root);

    int x = 603;
    if (searchInBST_Iterative(root, x) == true)
    {
        cout << x << " is present in BST.\n";
    }
    else
    {
        cout << x << " is not present in BST.\n";
    }
}