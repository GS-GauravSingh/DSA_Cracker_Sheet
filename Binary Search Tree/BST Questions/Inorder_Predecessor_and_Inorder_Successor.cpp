/*
Inorder Predecessor of x:- in inorder traversal of BST, the value comes just before x is the inorder predecessor of x.

Inorder Successor of x:- in inorder traversal of BST, the value comes just after x is the inorder successor of x.

Example:-
Suppose we have a inorder traversal of a bst.

Inorder Traversal :- 10 20 30 50 60 70 100 120.
we know that inorder traversal of BST comes out to be in a sorted manner.

Inorder Predecessor of 50:- 30
Inorder Successor of 50:- 60
*/

#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;

/*

To find predecessor of x:-
Step 1:- find x.
Step 2:- move to left one step and from here the rightmost node is the predecessor of x.

To find successor of x:-
Step 1:- find x.
Step 2:- move to right one step and from here the leftmost node is the successor of x.

*/

// Time Complexity:- O(height of the tree)
// Space Complexity:- O(1)

/* Function to find inorder predecessor of x in BST */
void inorderPredecessor(Node *root, Node *&pre, int x)
{
    // For Inorder Predecessor => we have to find a value which is just smaller then x.
    while (root != NULL)
    {
        if (x <= root->data)
        {
            root = root->left;
        }
        else
        {
            pre = root;
            root = root->right;
        }
    }
}

// Time Complexity:- O(height of the tree)
// Space Complexity:- O(1)

/* Function to find inorder successor of x in BST */
void inorderSuccessor(Node *root, Node *&suc, int x)
{
    // For Inorder Successor => we have to find a value which is just greater then x.
    while (root != NULL)
    {
        if (x >= root->data)
        {
            root = root->right;
        }
        else
        {
            suc = root;
            root = root->left;
        }
    }
}

/*
One more algo:-

1st:- find node.
2nd:- predecessor = maximum value from left subtree.
and successor = minimum value from right subtree.

Time Complexity:- O(n)
Space Complexity:- O(1)
*/
int main()
{
    /*
    Example TestCases:-

    Ex 1:- 10 8 7 21 27 5 4 3 -1
    Ex 2:- 21 10 5 15 50 40 60 35 70 -1

    */

    Node *root = NULL;
    Node *pre = NULL;
    Node *suc = NULL;
    BinarySearchTree bst;
    bst.takeInput(root);

    int x = 5;
    inorderPredecessor(root, pre, x);
    inorderSuccessor(root, suc, x);

    cout << "\nInorder Traversal:-\n";
    bst.InOrderTraversal(root);

    if (pre != NULL)
    {
        cout << "\nPredecessor of " << x << " = " << pre->data;
    }
    else{
        cout<<"\nPredecessor of "<<x<<" not present.";
    }
    if (suc != NULL)
    {
        cout << "\nSuccessor of " << x << " = " << suc->data;
    }
    else{
        cout<<"\nSuccessor of "<<x<<" not present.";
    }
}