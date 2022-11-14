/*
Question:-
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same Node class where the right child pointer points to the next   node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Example 1:

Input :
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6

Explanation:
After flattening, the tree looks
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6

Here, left of each node points
to NULL and right contains the
next node in preorder.The inorder
traversal of this flattened tree
is 1 2 3 4 5 6.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Approach:- use morris traversal.

*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Time Complexity:- O(n)
Space Complexity:- O(1)
*/
void flatten(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    Node *current = root;
    Node *predecessor;

    while (current != NULL)
    {
        // check if current -> left, exist's or not.
        if (current->left != NULL)
        {
            // if exist's, find inorder predecessor.
            predecessor = current->left;
            while (predecessor->right != NULL)
            {
                predecessor = predecessor->right;
            }

            // make connections, link left with the right subtree
            // predecessor -> right = current -> right;
            predecessor->right = current->right;

            // link root with the left subtree
            // current ->right = current -> left;
            current->right = current->left;

            // point current left to NULL.
            current->left = NULL;
        }

        // if current -> left, doesn't exist's then move to right.
        current = current->right;
    }
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

    flatten(root);
    bt.PreOrder_Traversal(root);
}