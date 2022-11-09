#include<bits/stdc++.h>
#include"Binary_Tree_Implementation.h"
using namespace std;

int main(){
    Node* root = NULL;
    BinaryTree bt;

    bt.BuildTree_LevelOrder(root);
    // InOrder Traversal
    cout << "\nInOrder Traversal (Print Order:- Left, Root, Right):-\n";
    bt.InOrder_Traversal(root);

    // PreOrder traversal
    cout << "\nPreOrder Traversal (Print Order:- Root, Left, Right):-\n";
    bt.PreOrder_Traversal(root);

    // PostOrder traversal
    cout << "\nPostOrder Traversal (Print Order:- Left, Right, Root):-\n";
    bt.PostOrder_Traversal(root);

    // LevelOrder traversal
    cout << "\nLevel Traversal (Print Order:- Level 0, Level 1 and so on..):-\n";
    bt.LevelOrder_Traversal(root);
}