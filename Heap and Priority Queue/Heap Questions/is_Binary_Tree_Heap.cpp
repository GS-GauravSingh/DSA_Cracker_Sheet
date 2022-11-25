#include <bits/stdc++.h>
#include "../../Binary Tree/Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;
/*
Approach 1:- sort the given array and return the k-1th index.

Time Complexity:- O(n)
Space Complexity:- O(n)
*/
/* Function to check if a given Binary Tree is Complete Binary Tree (CBT) or Not.*/
bool isCBT(Node *root, int i, int nodeCount)
{
    // i = index of current node.

    // Base Case
    if (root == NULL)
    {
        return true;
    }

    // if index(i) > total number of nodes(nodeCount), in this case return false.
    if (i >= nodeCount)
    {
        return false;
    }
    else
    {
        // if BT is a valid heap, then it's left child is at index 2*i+1 (0-based indexing).
        bool left = isCBT(root->left, 2 * i + 1, nodeCount);

        // if BT is a valid heap, it's right child is at index 2*i+2 (0-based indexing).
        bool right = isCBT(root->right, 2 * i + 2, nodeCount);

        return (left && right);
    }
}

/* Function to check if a given Binary Tree follows the MAX Heap property or Not.*/
bool isMAXProperty(Node *root)
{
    // to check if a given Binary Tree follows the MAX Heap property or Not there are 3 cases.
    /*
    1. Both child exists.
    2. Only left child exists.
    3. leaf node.
    */

    // leaf Node
    if (root->left == NULL && root->right == NULL)
    {
        // leaf node is a vaid heap.
        return true;
    }

    // Only left child exists.
    if (root->right == NULL)
    {
        // check if root -> data >= root -> left -> data.
        // if yes, return true.
        // else return false.

        if (root->data > root->left->data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Both left and right child exists.
    else
    {
        // check if root -> data >= root -> left -> data and root -> data >= root -> right -> data and
        // if yes, return true.
        // else return false.

        bool left = isMAXProperty(root->left);
        bool right = isMAXProperty(root->right);

        if (left && right && (root->data > root->left->data) && (root->data > root->right->data))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

/* Function to count total number of nodes in Binary Tree. */
int countNodes(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    // Recursive Case
    int left = countNodes(root->left);
    int right = countNodes(root->right);

    int ans = 1 + left + right;

    return ans;
}

bool isHeap(Node *tree)
{
    // if Binary tree follows the property of Heap, then BT is a valid heap else not.
    // property:- 1. BT must be complete binary tree.
    //            2. max or min heap property.

    // Base Case
    if (tree == NULL)
    {
        return true;
    }

    // if BT follows both the property, then return true, else return false.
    int index = 0;
    int nodeCount = countNodes(tree);
    if (isCBT(tree, index, nodeCount) && isMAXProperty(tree))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
    // Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

    /*
    Example Testcases:-

    Ex 1:- 5 2 -1 -1 3 -1 -1, this Binary Tree follows the max heap property.
    visualize:-                      5
                                   /   \
                                  2     3

    Ex 2:- 10 20 40 -1 -1 60 -1 -1 30 -1 -1,  this Binary Tree does not follow the max heap property.
    visualize:-                               10
                                             /   \
                                            20   30
                                          /   \
                                         40   60
    */
    Node *root = NULL;
    BinaryTree bt;
    bt.BuildTree_PreOrder(root);

    if (isHeap(root) == true)
    {
        cout << "Given Tree follows the MAX Heap property.\n";
    }
    else
    {
        cout << "Given Tree does not follow the MAX Heap property.\n";
    }
}