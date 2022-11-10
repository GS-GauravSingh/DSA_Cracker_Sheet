/*
Height of Binary Tree:-

1. Height of the tree is the maximum levels we have in a tree.
2. Height of the tree is the longest path b/w root node and leaf node. So, the number of nodes in this longest path from root to leaf node is the height of the tree.

Approach 1:- traverse the tree using level order traversal and count the levels.

height of binary tree = number of levels in a tree.

Approach 2:- calculate the height of left subtree and right subtree,
take the maximum of left and right and add 1 (root node).
int ans = max(left, right) + 1; // +1 is for adding root node.

*/

// Approach 1:- Using Level Order Traversal,  Time and Space Complexity of Level Order Traversal is O(N).

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

void LevelOrder_Traversal(Node *root, int &height)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // delimiter representing the end of current level.

    while (!q.empty())
    {
        Node *curr = q.front();
        if (curr == NULL)
        {
            height++;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();

            // push child node if exists.
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}


// Approach 2:- Calculate the depth of left and right subtree and take the maximum of left and right subtree and add 1 for root node.

// Time Complexity:- O(n)
// Space Complexity:- O(n)
int height(Node* root){
    // Base Case
    if(root == NULL){
        return 0;
    }

    // Recursive Case
    // Calculating the height of left subtree.
    int left = height(root -> left);

    // Calculating the height of right subtree.
    int right = height(root -> right);

    // take the maximum of left and right subtree and add 1 for height of root node.
    int height = max(left, right) + 1;

    // return height.
    return height;
}

int main()
{
    /*
    Exmaple TestCases:-

    Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , Height = 3.
    view:-                      1                           level 0
                        3               5                   level 1
                    7      11       17      -1              level 2
                -1  -1  -1  -1   -1   -1                    level 3


    Ex 2:-  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1, Height = 4.
    view:-                          1                        level 0
                        2                   3                level 1
                    4       5           -1      6            level 2
                 -1  -1   7   -1             -1   -1         level 3
                       -1  -1                                level 4

    */

    // Building tree
    Node *root = NULL;
    BinaryTree bt;
    bt.BuildTree_PreOrder(root);

    // Approach 1,
    // int height = 0;
    // LevelOrder_Traversal(root, height);
    // cout<<height<<endl;

    // Approach 2,
    cout<<height(root);
}