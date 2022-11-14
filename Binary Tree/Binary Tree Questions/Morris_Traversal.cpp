/*
Using Morris Traversal, we can traverse the tree without using stack and recursion.

Algorithm:-
Node* current = root;
while(current != NULL){

    if( current -> left does not exist){
        print (current);
        move right (current = current -> right);
    }
    else{
        // if current -> left exist's.
        // find inorder predecessor :- current ke left me jao ek bar or current -> left se jo rightmost node hogi vo predecessor hai.

        prdecessor = find(current);

        // temporary link making.
        if(predecessor -> right == NULL){
            // if yes, then make a temporary connection of predecessor -> right = current;
            predecessor -> right = current;

            current = current -> left; // move left;

        }
        // temporary link removing.
        else{
            // if prdecessor -> right != NULL, the make  predecessor -> right = NULL;
            // print current;
            // move right.

            predecessor -> right = NULL;
            print(current);
            current = current -> right;

        }


    }
}

Time Complexity of Morris Traversal:- O(n)
Space Complexity of Morris Traversal:- O(1)
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/* Morris Traversal Function */
void MorrisTraversal(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Step 1:- initialize current as root.
    Node *current = root;
    Node *predecessor;

    // Step 2:- run a while loop till current != NULL.
    while (current != NULL)
    {

        // Step 3:- if current -> left does not exist's,
        // then print current -> data and move to right.
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            // Step 4:- if current -> left exist's,
            // step 4.1:- find inorder predecessor;
            // current ke left me jao ek bar or current -> left se jo rightmost node hogi vo predecessor hai.
            predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            // step 4.2:- check if predecessor -> right == NULL.
            // if yes, then make temporary link with current.
            // predecessor -> right = current and move left.
            if (predecessor->right == NULL)
            {
                predecessor->right = current;
                current = current->left;
            }
            // if no, then remove temporary link with current.
            // predecessor -> right = NULL, print current -> data and move right.
            else
            {
                predecessor->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

int main()
{
    /*
    Exmaple TestCases:-

    Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 ,
    view:-                      1                           level 0
                        3               5                   level 1
                    7      11       17      -1              level 2
                -1  -1  -1  -1   -1   -1                    level 3


    Ex 2:-  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1,
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

    // morris traversal
    cout<<"\nInOrder Traversal Output:-\n";
    bt.InOrder_Traversal(root);
    cout<<"\nMorris Traversal Output:-\n";
    MorrisTraversal(root);
}