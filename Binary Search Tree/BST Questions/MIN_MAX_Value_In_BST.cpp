#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;

// Time Complexity:- O(n)
// Space Complexity:- O(1)

/* Function to find minimum value in BST */
int findMinimum(Node *root)
{
    // we know that in case of BST, the minimum value is present at the leftmost node in the BST.

    // Base Case
    if (root == NULL)
    {
        return -1;
    }

    Node *curr = root;
    while (curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr->data;
}

/* Function to find maximum value in BST */
int findMaximum(Node *root)
{
    // we know that in case of BST, the maximum value is present at the rightmost node in the BST.

    // Base Case
    if (root == NULL)
    {
        return -1;
    }

    Node *curr = root;
    while (curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr->data;
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

    cout << "Minimum Value = " << findMinimum(root) << endl;
    cout << "Maximum Value = " << findMaximum(root) << endl;
}