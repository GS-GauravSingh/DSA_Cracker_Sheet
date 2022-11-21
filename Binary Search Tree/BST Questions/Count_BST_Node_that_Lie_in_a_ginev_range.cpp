#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;

/*
Time Complexity:- O(n)
Space Complexity:- O(height of the tree)
*/

void InOrderTraversal(Node *root, int &count, int low, int high)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Recursive Case
    InOrderTraversal(root->left, count, low, high);
    if (root->data >= low && root->data <= high)
    {
        count++;
    }
    InOrderTraversal(root->right, count, low, high);
}

int getCount(Node *root, int l, int h)
{
    // your code goes here
    int count = 0;
    InOrderTraversal(root, count, l, h);
    return count;
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

    int l = 5;
    int h = 50;
    cout<<getCount(root, l , h);
}