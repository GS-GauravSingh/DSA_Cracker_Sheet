#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;

/*
Time Complexity:- O(n)
Space Complexity:- O(n)
*/
Node* solve(vector<int> &preorder, int minn, int maxx, int &i){
    // Base Cases
    if(i >= preorder.size()){
        return NULL;
    }
    if(preorder[i] < minn || preorder[i] > maxx){
        return NULL;
    }

    // Recursive Case
    Node* root = new Node(preorder[i++]);
    root -> left = solve(preorder, minn, root ->data, i);
    root -> right = solve(preorder, root ->data, maxx, i);

    return root;
}

Node *preorderToBST(vector<int> &preorder)
{
    int minn = INT_MIN;
    int maxx = INT_MAX;
    int i=0;
    
    return solve(preorder, minn, maxx, i);
}

int main()
{
    /*
    Ex 1:- 21 10 5 15 50 40 60 35 70 -1
    Ex 2:- 50 20 70 10 30 90 110 -1
    */
    vector<int> preorder = {20, 10, 5, 15, 13, 35, 30, 42};
    Node* root = preorderToBST(preorder);

    BinarySearchTree bst;
    bst.LevelOrderTraversal(root);
}