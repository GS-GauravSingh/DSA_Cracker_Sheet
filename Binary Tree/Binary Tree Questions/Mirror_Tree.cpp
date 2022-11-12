/*
Question:-
Given a binary tree, the task is to create a new binary tree which is a mirror image of the given binary tree.

Input:
      1
    /  \
   2    3
Output: 3 1 2

Explanation: The tree is
   1    (mirror)  1
 /  \    =>      /  \
2    3          3    2
The inorder of mirror is 3 1 2
*/

/*
Time Complexity:- O(N).
Space Complexity:- O(h), h is the height of the tree.
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/* Function to convert a binary tree into its mirror tree. */
void mirror(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Recursive Case
    mirror(root->left);
    mirror(root->right);

    // Backtracking Step(while comming back from the base case).
    // we have to swap (root -> left, root -> right);
    swap(root->left, root->right);
}

/* pre-order traversal */
void preOrder(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // print the data;
    cout<<root->data<<" ";

    // Recursive Case
    preOrder(root->left);
    preOrder(root->right);

}

int main()
{
    /*
 Exmaple TestCases:-

 Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 18 19 -1 -1 -1 -1 -1,
 view:-                      1                           level 0
                     3               5                   level 1
                 7      11       17      -1              level 2
             -1  -1  -1  -1   18   -1                    level 3
                            19   -1
                         -1   -1


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

    cout<<"PreOrder of Original Tree:-\n";
    bt.PreOrder_Traversal(root);

    // mirror tree
    cout<<"\nPreOrder of Mirror Tree:-\n";
    preOrder(root);

}