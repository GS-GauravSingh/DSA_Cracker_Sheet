/*
Question:- find kth smallest element from a given BST.

Approach 1:- find inorder traversal of tree and store it in vector, and return n-kth index element from vector.

Time Complexity:- O(n)
Space Complexity:- O(n)

Approach 2:- do reverse inorder traversal and take a counter, incredement and decrement the counter according to left and right recursive call and when counter reaches to k return thet element.

Time Complexity:- O(n)
Space Complexity:- O(n)
*/
#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;

/*
Time Complexity:- O(n)
Space Complexity:- O(height of the tree)

you can optimise this code using morris traversal.
*/
int kthLargestElement(Node* root, int &i, int k){
    // Base Case
    if(root == NULL)
    {
        return -1;
    }

    // Recursive Case
    // Reverse Inorder Traversal,

    
    // Right
    int right = kthLargestElement(root -> right, i, k);
    if(right != -1){
        return right;
    }

    // Root
    i++;
    if(i == k){
        return root -> data;
    }

    // Left
    int left = kthLargestElement(root -> left, i, k);

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

    int i = 0;
    int k = 2;

    
}