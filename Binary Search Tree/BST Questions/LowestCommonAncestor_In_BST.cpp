#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;

/*
Time Complexity:- O(height of the Tree)
Space Complexity:- O(1)
*/

Node *lca(Node *root, Node *p, Node *q)
{
    // Base CAse
    if (root == NULL)
    {
        return root;
    }

    while (root != NULL)
    {
        if (root->data < p->data && root->data < q->data)
        {
            // if root -> data is < p -> data and q -> data, it means p and q are present at right subtree.
            root = root ->right;
        }

        else if (root->data > p->data && root->data > q->data)
        {
            // if root -> data is > p -> data and q -> data, it means p and q are present at left subtree.
            root = root ->left;
        }

        else{
            // if ( (root -> data is > p -> data) && (root -> data < q -> data) ) ||
            //    ( (root -> data is < p -> data) && (root -> data > q -> data) );
            // in this case your root is the lca, return root.
            return root;
        }
        
        
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

    Node* p = new Node(20);
    Node* q = new Node(70);
    Node* ans = lca(root, p , q);
    cout<<ans->data<<endl;

}