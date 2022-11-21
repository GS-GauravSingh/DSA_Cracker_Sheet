#include<bits/stdc++.h>
#include"BST_Implementation.h"
// #include "../BST Implementation/BST_Implementation.h"
using namespace std;

int main(){
    /*
    Ex 1:- 21 10 5 15 50 40 60 35 70 -1
    Ex 2:- 50 20 70 10 30 90 110 -1

    */
    Node* root = NULL;

    BinarySearchTree bst;
    bst.takeInput(root);
    cout<<"\nInOrder Traversal:-\n";
    bst.InOrderTraversal(root);

    root = bst.deleteFromBST(root, 50);
    cout<<"\nAfter Deletion, InOrder Traversal:-\n";
    bst.InOrderTraversal(root);

    
}