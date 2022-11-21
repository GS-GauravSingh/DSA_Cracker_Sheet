#include <bits/stdc++.h>
#include "../BST Implementation/BST_Implementation.h"
using namespace std;
/*
Approach 1:- store the inorder traversal of both the BST's into 2 seperate vectors. after this, merge both the vectors and create BST from this sorted vector.

Time Complexity:- O(m+n)
Space Complexity:- O(m+n)

Approach 2:- store the inorder traversal of both the BST's into linked list. after this, merge both the linked lists and create BST from this sorted linked list.

Time Complexity:- O(m+n)
Space Complexity:- O(h1+h2)

*/

// ------------- Apptoach 1:- code -----------------------------

// Time Complexity:- O(m+n)
// Space Complexity:- O(m+n)
// void InOrderTraversal(Node *root, vector<int> &inorder)
// {
//     // Base Case
//     if (root == NULL)
//     {
//         return;
//     }

//     // Recursive Case
//     InOrderTraversal(root->left, inorder);
//     inorder.push_back(root->data);
//     InOrderTraversal(root->right, inorder);
// }

// vector<int> merge2sortedVector(vector<int> arr1, vector<int> arr2)
// {
//     // Base Case
//     if (arr1.size() == 0)
//     {
//         return arr2;
//     }
//     if (arr2.size() == 0)
//     {
//         return arr1;
//     }

//     // merge
//     vector<int> head;
//     int i = 0, j = 0;
//     while (i < arr1.size() && j < arr2.size())
//     {
//         if (arr1[i] < arr2[j])
//         {
//             head.push_back(arr1[i++]);
//         }
//         else
//         {
//             head.push_back(arr2[j++]);
//         }
//     }

//     while (i < arr1.size())
//     {
//         head.push_back(arr1[i++]);
//     }

//     while (j < arr2.size())
//     {
//         head.push_back(arr2[j++]);
//     }

//     return head;
// }

// Node *inorderToBST(vector<int> &inorder, int start, int end)
// {
//     // Base Case
//     if (start > end)
//     {
//         return NULL;
//     }

//     int mid = (start + end) / 2;
//     Node *root = new Node(inorder[mid]);
//     root->left = inorderToBST(inorder, start, mid - 1);
//     root->right = inorderToBST(inorder, mid + 1, end);
//     return root;
// }

// Node *mergeBST(Node *root1, Node *root2)
// {
//     // step 1:-  store the inorder traversal of both the BST.
//     vector<int> inorder_1;
//     vector<int> inorder_2;

//     InOrderTraversal(root1, inorder_1);
//     InOrderTraversal(root2, inorder_2);

//     // step 2:-  merge both the vectors.
//     vector<int> merge = merge2sortedVector(inorder_1, inorder_2);

//     // step 3:- create BST from inorder.
//     Node* root = inorderToBST(merge, 0, merge.size()-1);

//     return root;
// }
// ------------- Apptoach 1:- code ends here----------------------

// ------------------ Approach 2:- code --------------------------

/* Function to convert BST to Doubly Linked List. */
void convertIntoSortedDLL(Node *root, Node *&head, Node *&prev)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Recursive Case
    // make a recursive call to left part.
    convertIntoSortedDLL(root->left, head, prev);

    // process root node.
    if (prev == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    // make a recursive call to right part.
    convertIntoSortedDLL(root->right, head, prev);
}

/* Function to merge 2 sorted Doubly Linked List. */
Node *merge2sortedDLL(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {

        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head;

                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;

                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head;

                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;

                head2 = head2->right;
            }
        }
    }

    // if head1 is not empty.
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;

        head1 = head1->right;
    }

    // if head2 is not empty.
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;

        head2 = head2->right;
    }

    return head;
}

/* Function to count number of Nodes in DLL. */
int countNodes(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->right;
    }
    return count;
}

/* Function to convert sorted DLL to BST. */
Node *sortedLLToBST(Node *&head, int n)
{
    // Base Case
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    // Recursive Case

    // left part.
    Node *left = sortedLLToBST(head, n / 2);

    // root node
    Node *root = head;
    root->left = left;

    head = head->right;

    // right part
    Node *right = sortedLLToBST(head, n - n / 2 - 1);
    root->right = right;

    return root;
}

/* Function to merge 2 BST. */
Node *mergeBST(Node *root1, Node *root2)
{
    // step 1:-  convert sorted BST into sorted DLL (in-place).
    Node *head1 = NULL;
    Node *prev1 = NULL;
    convertIntoSortedDLL(root1, head1, prev1);

    Node *head2 = NULL;
    Node *prev2 = NULL;
    convertIntoSortedDLL(root2, head2, prev2);

    // step 2:-  merge both the linked lists.
    Node *merge = merge2sortedDLL(head1, head2);

    // step 3:- convert sorted LL into BST.
    /*
    Approach to convert Linked List into BST:-

    Suppose the number of node in DLL is n.
    1st. first n/2 nodes se left subtree bna lo.
    2nd. then (n/2+1) waali node se root node bna lo.
    3rd. rest of the nodes se right subtree bna lo.
    {
        total nodes = n;
        first n/2 nodes => left subtree. (n/2 nodes left).
        then (n/2+1)th node => root node. (n - n/2 - 1 nodes left).
        then create right subtree from rest of the nodes (n - n/2 - 1).
    }
    */
    int n = countNodes(merge);
    Node* ans = sortedLLToBST(merge, n);

    return ans;
}
// ------------- Apptoach 2:- code ends here----------------------

int main()
{
    /*
    Ex 1:- 21 10 5 15 50 40 60 35 70 -1
    Ex 2:- 50 20 70 10 30 90 110 -1
    */
    Node *root1 = NULL;
    Node *root2 = NULL;
    BinarySearchTree bst;
    bst.takeInput(root1);
    bst.takeInput(root2);

    Node *head = mergeBST(root1, root2);
    bst.LevelOrderTraversal(head);
}