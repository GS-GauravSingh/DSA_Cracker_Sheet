#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;

/*
Time Complexity:- O(n)
Space Complexity:- O(height of the tree)
*/
bool solve(Node *root, int minn, int maxx)
{
    // Base Case
    if (root == NULL)
    {
        return false;
    }

    if (root->data - 1 <= minn && root->data + 1 >= maxx)
    {
        return true;
    }

    // Recursive Case
    bool left = solve(root->left, minn, root->data);
    bool right = solve(root->right, root->data, maxx);

    return (left || right);
}
bool isDeadEnd(Node *root)
{
    return solve(root, 0, INT_MAX);
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

    cout<<isDeadEnd(root);
}