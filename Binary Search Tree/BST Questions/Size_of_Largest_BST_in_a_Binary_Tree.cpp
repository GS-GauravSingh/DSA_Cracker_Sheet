#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;

/*
Approach 1 (Brute Force):- visit each and every node and check if it creates a valid BST or not, if yes the store the size of BSt, else not.
Time Complexity:- O(n^2)
Space Complexity:- O(n^2)

Approach 2 (Optimized):- this is the optimization of above approach. The logic is, that nodes which is already processesd don't process it again.
Time Complexity:- O(n)
Space Complexity:- O(height of the tree) in worst case O(n).
*/

class Info
{
    /*
    So, for each node, we have to know the maximum value of left subtree and minimum value of right subtree. But why?
    because for valid BST  this condition needs to be true,
    { left subtree maximum value < root -> data < right subtree minimum value }.

    also we need to know, if the left and right subtree is valid BST or not.

    and last we need size variable to store the size of valid BST.
    */
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

Info solve(Node *root, int &ans)
{
    // Base Case
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    // Recursive Case

    // left part.
    Info left = solve(root->left, ans);

    // right part.
    Info right = solve(root->right, ans);

    // root node.
    Info currNode;

    // update size.
    currNode.size = left.size + right.size + 1; // +1 for adding size of root node.

    // update maxi, maximum value came from right.
    currNode.maxi = max(right.maxi, root->data);

    // update mini, minimum value came from left.
    currNode.mini = min(left.mini, root->data);

    // check if left, right and root is valid BST or not.
    if (left.isBST == true && right.isBST == true && (left.maxi < root->data && right.mini > root->data))
    {
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    // update answer (store maximum size if it is a vlid BST).
    if(currNode.isBST == true){
        ans = max(ans,currNode.size);
    }

    return currNode;
}

int largestBST(Node *root)
{
    // variable to stroe maximum size of valid BST.
    int maxSize = 0;

    Info ans = solve(root, maxSize);
    return maxSize;
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
}