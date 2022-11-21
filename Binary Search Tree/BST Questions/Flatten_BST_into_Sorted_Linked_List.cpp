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

Node *flatten(Node *root)
{
    // step 1:- store the inorder traversal of BST.
    // we know that inorder traversal of BST came out to be in sorted order.
    vector<int> inorder;
    InOrderTraversal(root, inorder);

    // step 2:- create linked list from inorder vector.
    Node *head = NULL;
    Node *tail = NULL;

    // creating head node.
    head = new Node(inorder[0]);
    tail = head;

    for (int i = 1; i < inorder.size(); i++)
    {
        Node* newNode = new Node(inorder[i]);
        tail->right = newNode;
        tail = newNode;
    }

    return head;
    
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

    Node* head = flatten(root);

    while(head != NULL){
        cout<<head->data<<"->";
        head = head -> right;
    }
    cout<<"NULL";
}