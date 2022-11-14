#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Approach:-

in-order = left, root, right
pre-order = root, left, right

1. take index element as root element from preorder.
2. find root element position in in-order.
3. make a recursive call on left and right.

Time Complexity:- O(N^2)
Space Complexity:- O(N)
*/

/* Function to find position of root element in inorder array

To optimized this code, use map instead of iterating everytime in inorder array to find position of root element.

after using map
Time Complexity:- O(N log N)
Space Complexity:- O(N)
 */
int findPosition(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeIndex)
{
    // Base Case
    if (index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // Recursive Case

    // make root node from preorder
    int element = pre[index++];
    Node *root = new Node(element);

    // find position of root node in inorder array.
    // int position = findPosition(in, element, n);
    int position = nodeIndex[element];

    // recursive calls
    root->left = solve(in, pre, index, inorderStart, position - 1, n, nodeIndex);
    root->right = solve(in, pre, index, position + 1, inorderEnd, n, nodeIndex);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    int startIndexInorder = 0;
    int endIndexInorder = n - 1;
    int preOrderIndex = 0;

    // store index of all element of inoder array in map.
    map<int, int> nodeIndex;
    for (int i = 0; i < n; i++)
    {
        nodeIndex[in[i]] = i;
    }

    Node *ans = solve(in, pre, preOrderIndex, startIndexInorder, endIndexInorder, n, nodeIndex);
    return ans;
}

int main()
{
    int inorder[] = {1, 6, 8, 7};
    int preorder[] = {1, 6, 7, 8};
    int n = sizeof(inorder) / sizeof(preorder[0]);

    Node *root = buildTree(inorder, preorder, n);

    BinaryTree bt;
    bt.PostOrder_Traversal(root);
}