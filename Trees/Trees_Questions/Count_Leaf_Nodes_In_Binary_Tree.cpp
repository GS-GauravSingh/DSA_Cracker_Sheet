#include<bits/stdc++.h>
using namespace std;

class Node
{
private:
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    // getting the data for node.
    cout << "Enter the data:-\n";
    int data;
    cin >> data;

    // creating a node with given data.
    root = new Node(data);

    // -1 represents NULL.
    if (data == -1)
    {
        return NULL;
    }

    // insert data at left
    cout << "Enter data to insert at left of " << data << "\n";
    root->left = buildTree(root->left); // making a recursive call for left side.

    // Backtracking Step,
    // insert data at right
    cout << "Enter data to insert at right of " << data << "\n";
    root->right = buildTree(root->right); // making a recursive call for right side.

    return root;
}


/* InOrder Traversal :- Recursive function for printing Tree. */

// Time Complexity:- O(n)
// Space Complexity:- O(h), h is the height of the tree. 
void InOrder_Traversal(Node *root, int &count)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Recursive case
    // make a recursive call on left and right side.
    InOrder_Traversal(root->left, count);
    if(root -> left == NULL && root -> right == NULL){
        count++;
    }
    InOrder_Traversal(root->right, count);
}

int main(){

    Node* root = NULL;
    root = buildTree(root);

    int count = 0;
    // counting leaf nodes.
    InOrder_Traversal(root, count);
    cout<<count;
}