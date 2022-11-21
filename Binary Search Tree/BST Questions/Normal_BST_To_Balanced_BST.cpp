/*
Balanced BST:- for every node if( abs( height of (left subtree) - height of(right subtree) ) <= 1).
if the above condition is true for every node then the BST is balanced.

Our Task:- We have to convert the give BST to Balnced BST.
*/

#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;

/*
Time Complexity:- O(n)
Space Complexity:- O(n)
*/
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

Node *inorderToBST(int start, int end, vector<int> inorder)
{
    // Base Case
    if (start > end)
    {
        return NULL;
    }

    // Recursive case

    int mid = (start + end) / 2;
    Node *root = new Node(inorder[mid]);

    root->left = inorderToBST(start, mid - 1, inorder);
    root->right = inorderToBST(mid + 1, end, inorder);

    return root;
}

Node *balancedBst(Node *root)
{

    // step 1:- store the inorder traversal of BST.
    // we know that inorder traversal of BST came out to be in sorted order.
    vector<int> inorder;
    InOrderTraversal(root, inorder);

    // step 2:- find mid value of inorder vector.
    // root node = mid;
    // root -> left = start to mid-1
    // root -> right = mid + 1 to end.
    return inorderToBST(0, inorder.size() - 1, inorder);
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

    Node* root = balancedBst(root);
}