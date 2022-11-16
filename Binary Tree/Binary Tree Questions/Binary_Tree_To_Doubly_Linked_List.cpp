/*
Question:-
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

     1
    /  \
   3    2
Output:
3 1 2

Explanation: DLL would be 3<=>1<=>2
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Time Comlexity:- O(n)
Space Comlexity:- O(height of the tree)
*/

// creating previous and head pointer for DLL.
Node *previous = NULL;
Node *head = NULL;

void convertToDLL(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // Recursive Case,
    // first process the leftmost node.
    convertToDLL(root->left);

    if (previous == NULL)
        // if previous == NULL, it means we have to set our head first.
        // because, in DLL head -> prev points to NULL;
        head = root;

    else
    {
        // if previous != NULL, means our head is already set.
        // we have to set next (right) and previous (left) pointer.
        root->left = previous;
        previous->right = root;
    }

    // update previous.
    previous = root;

    // in last, process right node.
    convertToDLL(root->right);
}

Node *bToDLL(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return NULL;
    }

    convertToDLL(root);
    return head;
}

/* function to print DLL */
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->right;
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

    Node *head = bToDLL(root);
    print(head);
}