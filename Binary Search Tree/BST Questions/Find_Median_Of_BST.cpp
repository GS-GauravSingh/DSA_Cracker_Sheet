/*
Questions:- Given a Binary Search Tree of size N, find the Median of its Node values.

Example 1:

Input:
       6
     /   \
   3      8
 /  \    /  \
1    4  7    9
Output: 6
Explanation: Inorder of Given BST will be:
1, 3, 4, 6, 7, 8, 9. So, here median will 6.


Approach 1:- store the inorder traversal of BST into vector and return the median value.
If number of nodes are even: then median = (N/2 th node + (N/2)+1 th node)/2
If number of nodes are odd : then median = (N+1)/2th node.


Approach 2:- 
1. Count the number of nodes in the given BST using Morris Inorder Traversal.
2. Then perform Morris Inorder traversal one more time by counting nodes and by checking if the count is equal to the median point.
3. To consider even no. of nodes, an extra pointer pointing to the previous node is used.
*/

#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;

/*
Approach 1:- code,
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

float findMedian(struct Node *root)
{
    // step 1:- store the inorder traversal of BST.
    // we know that inorder traversal of BST came out to be in sorted order.
    vector<int> inorder;
    InOrderTraversal(root, inorder);
    int n = inorder.size();

    // step 2:- return median acc. to number of nodes.

    if (n & 1)
    {
        // odd number of nodes.
        // If number of nodes are odd : then median = (N+1)/2th node.
        int medianIdx = (n + 1) / 2;
        return inorder[medianIdx - 1]; // -1 is for 0-based indexing.
    }
    else
    {

        // even number of nodes.
        // If number of nodes are even: then median = (N/2 th node + (N/2)+1 th node)/2

        int medianIdx = (n / 2);
        return (inorder[medianIdx - 1] + inorder[medianIdx + 1 - 1]) / 2.0; // -1 is for 0-based indexing.
    }
}

//-------------------------------- Approach 1:- code ends here. -----------------------------------

int main()
{
    /*
    Ex 1:- 21 10 5 15 50 40 60 35 70 -1
    Ex 2:- 50 20 70 10 30 90 110 -1
    */

    Node *root = NULL;
    BinarySearchTree bst;
    bst.takeInput(root);
}