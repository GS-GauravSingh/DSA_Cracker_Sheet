#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Approach:-

in-order = left, root, right
post-order = left, right, root


Time Complexity:- O(N log N)
Space Complexity:- O(N)
*/

// Function to return a tree created from postorder and inoreder traversals.
Node *solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeIndex)
{
    // Base Case
    if (index < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // Recursive Case

    // make root node from preorder
    int element = post[index--];
    Node *root = new Node(element);

    // find position of root node in inorder array.
    // int position = findPosition(in, element, n);
    int position = nodeIndex[element];

    // recursive calls
    // in case of inorder and postorder build,
    // first build right subtree then left subtree.
    root->right = solve(in, post, index, position + 1, inorderEnd, n, nodeIndex);
    root->left = solve(in, post, index, inorderStart, position - 1, n, nodeIndex);

    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    int startIndexInorder = 0;
    int endIndexInorder = n - 1;
    int postOrderIndex = n - 1;

    // store index of all element of inoder array in map.
    map<int, int> nodeIndex;
    for (int i = 0; i < n; i++)
    {
        nodeIndex[in[i]] = i;
    }

    Node *ans = solve(in, post, postOrderIndex, startIndexInorder, endIndexInorder, n, nodeIndex);
    return ans;
}

int main()
{
    int inorder[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int postorder[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(inorder) / sizeof(postorder[0]);

    Node *root = buildTree(inorder, postorder, n);

    BinaryTree bt;
    bt.PreOrder_Traversal(root);
}