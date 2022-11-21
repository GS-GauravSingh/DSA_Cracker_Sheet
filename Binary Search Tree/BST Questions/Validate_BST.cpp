/*
Question:- Check if a given tree is BST or not.

Approach 1:- find inorder traversal of tree and store it in vector, and check if the vector is sorted it means give tree is valid BST else if vecotor is not sorted  it means tree is not valid BST.

Time Complexity:- O(n)
Space Complexity:- O(n)

Approach 2:- find inorder traversal of tree and store it in vector, and check if the vector is sorted it means give tree is valid BST else if vecotor is not sorted  it means tree is not valid BST.

Time Complexity:- O(n)
Space Complexity:- O(n)
*/

#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;

/*
Time Complexity:- O(n)
Space Complexity:- O(n)
*/
bool isBSTValid(Node *root, int minn, int maxx)
{
    // Base Case
    // Empty tree is a valid BST.
    if (root == NULL)
    {
        return true;
    }

    // Recursive Case
    if(root -> data >= minn && root -> data <= maxx){
        bool left = isBSTValid(root ->left, minn, root -> data);
        bool right = isBSTValid(root ->right, root->data, maxx);

        return (left&&right);
    }
    else{
        return false;
    }

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

    if (isBSTValid(root, INT_MIN, INT_MAX))
    {
        cout << "Given tree is valid BST.\n";
    }
    else
    {
        cout << "Given tree is not a valid BST.\n";
    }
}