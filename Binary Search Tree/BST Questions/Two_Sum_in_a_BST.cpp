#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;

/*
Approach 1 (Brute force):- for every node if (target - root -> data) exist's in the tree the you can make the pair of (root -> data, this value).
Time Complexity:- O(n^2)
Space Complexity:- O(n)

Approach 2 (Optimized):- store the inorder traversal of BST into vector, apply 2 pointer approach on the vector and find the pair.
Time Complexity:- O(n)
Space Complexity:- O(n)

*/


/*
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

bool twoSumInBST(Node *root, int target)
{
    // you have to find a pair of nodes whose sum is equal to the given target.

    // store inorder tarversal into vector.
    vector<int> inorder;
    InOrderTraversal(root, inorder);

    // check if pair exist's using two pointer apporoach.
    int start = 0;
    int end = inorder.size() - 1;
    while (start < end)
    {
        int a = inorder[start];
        int b = inorder[end];
        int sum = a + b;

        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return false;
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

    int target = 20;
    if(twoSumInBST(root, target)){
        cout<<"Pair Found.\n";
    }
    else{
        cout<<"Pair not Found.\n";

    }
}