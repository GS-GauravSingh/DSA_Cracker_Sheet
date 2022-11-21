#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
// #include "../../Binary Tree/Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Time Complexity:- O(n log n)
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

Node *binaryTreeToBST(Node *root)
{
    // step 1:- store the inorder traversal of BST.
    vector<int> inorder;
    InOrderTraversal(root, inorder);
    // step 2:- soor the inorder array.
    sort(inorder.begin(), inorder.end());

    // step 3:- create BST from sorted inorder vector.
    return inorderToBST(0, inorder.size() - 1, inorder);
}

int main()
{
    /*
    Binary Tree Examples:-
Exmaple TestCases:-

Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 18 19 -1 -1 -1 -1 -1,
view:-                      1                           level 0
                  3               5                   level 1
              7      11       17      -1              level 2
          -1  -1  -1  -1   18   -1                    level 3
                         19   -1
                      -1   -1


Ex 2:-  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1,
view:-                          1                        level 0
                  2                   3                level 1
              4       5           -1      6            level 2
           -1  -1   7   -1             -1   -1         level 3
                 -1  -1                                level 4

*/



    // // BT
    // Node *rootBT = NULL;
    // BinaryTree bt;
    // bt.BuildTree_PreOrder(rootBT);

    // // BSt
    // BinarySearchTree bst;

    // Node *root = binaryTreeToBST(root);
    // bst.LevelOrderTraversal(root);
}