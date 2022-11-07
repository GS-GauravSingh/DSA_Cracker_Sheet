/*

Binary Tree:- A tree is called Binary Tress, if each node has 0 child, 1 child or 2 child. Empty tree is also a valid binary tree.

In Short:-
Binary Tree => each node has <= 2 child.
*/

#include <bits/stdc++.h>
using namespace std;

/* Node Structure for Binary Tree */

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

/* Recursive Function to Build Tree

First we build the root node, then we build the left nodes, and then we build the right nodes, this way of building tree is know as Pre-order Build.

*/
Node *buildTree(Node *root)
{
    // getting the data for node.
    // cout << "Enter the data:-\n";
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
    // cout << "Enter data to insert at left of " << data << "\n";
    root->left = buildTree(root->left); // making a recursive call for left side.

    // Backtracking Step,
    // insert data at right
    // cout << "Enter data to insert at right of " << data << "\n";
    root->right = buildTree(root->right); // making a recursive call for right side.

    return root;
}

/*
A Binary Tree is a data structure where every node has at-most two children. The topmost node is called the Root node.

There are 4 common ways of traversing the nodes of a Binary Tree, namely:
1. In order Traversal
2. Pre Order Traversal
3. Post Order Traversal
4. Level Order Traversal

1. In order Traversal:- first left subtree is visited after that root node is traversed, and finally, the right subtree is traversed.

in short:- InOrder Traversal =  Left, Root, Right.

2. PreOrder Traversal :- jis order me tree create kiya usi order me elements ko print krte hai preorder traversal me.

first root node is visited after that the left subtree is traversed recursively, and finally, right subtree is recursively traversed.

in short:- PreOrder Traversal = Root, Left, Right.

3. Post Order Traversal:-  Left, Right, Root. Also know as bottom up traversal.

4. Level Order Traversal:- also know as Breadth First Search (BFS), means printing in levels,
first we print the root node present at level 0, then we print the elements present at level 1, then level 2, level 3 and so on.

*/

/* InOrder Traversal :- Recursive function for printing Tree. */
void InOrder_Traversal(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Recursive case
    // make a recursive call on left and right side.
    InOrder_Traversal(root->left);
    cout << root->data << " ";
    InOrder_Traversal(root->right);
}

/* PreOrder Traversal :- Recursive function for printing Tree. */
void PreOrder_Traversal(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Recursive case
    cout << root->data << " ";

    // make a recursive call on left and right side.
    PreOrder_Traversal(root->left);
    PreOrder_Traversal(root->right);
}

/* PostOrder Traversal :- Recursive function for printing Tree. */
void PostOrder_Traversal(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Recursive case
    // make a recursive call on left and right side.
    PostOrder_Traversal(root->left);
    PostOrder_Traversal(root->right);
    cout << root->data << " ";
}

/* LevelOrder Traversal also Known as Breadth First Search (BFS) */
/*

Level order traversal means print in levels, It means first we need to print the root node present at level 0, then we need to print all elements present at level 1, then level 2, level 3 asn so on.

Approach:- using Queue.

Step 1. declare queue of node*.  queue<node*> q;
Step 2. push root node into queue, because at first root node is printed.
    q.push(root);
Step 3. run a loop while queue is not empty and do the following things,
    3.1. store the front node present at queue (Node* temp = q.front()).
    3.2. pop the front element of queue. (q.pop()).
    3.2. print the data present at front (cout<<temp -> data).
    3.3. push the children nodes of front node (store at temp) present at queue in the queue if it is not NULL.

when queue is empty all elements will be printed in single line.

To get the output in levels, you need a delimiter that denotes the ending of particular level.

*/
void LevelOrder_Traversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // delimiter representing the end of level 0.

    // Remember at the end of any level, our queue will contain childrens of current level if present.
    // So, whenever you pop out NULL, push another NULL, but the corner case is when the current level has no childrens, in that case when you pop out NULL our queue is empty then there is no need to push another NULL.

    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp == NULL)
        {
            // temp == NULL, means current lvele is end and our queue will contains childrens of nodes present at current level.
            cout << endl;
            q.pop();

            // Inserting a new NULL for next level.
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {   
            // pop it.
            q.pop();
            // print the data.
            cout << temp->data << " ";

            // push left and right chile into queue if exists.
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

/* Main Function */
int main()
{
    Node *root = NULL; // initializing our root node of the tree.
    // initially our root node is NULL, because initially it is not poiniting to any other node.

    // creating a tree (PreOrder Build).
    root = buildTree(root);

    /* Data:-
    Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    view:-                      1                           level 0
                        3               5                   level 1
                    7      11       17      -1              level 2
                -1  -1  -1  -1   -1   -1                    level 3


    Ex 2:- 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

    view:-                          1                        level 0
                        2                   3                level 1
                    4       5           -1      6            level 2
                 -1  -1   7   -1             -1   -1         level 3
                       -1  -1                                level 4
    */

    // InOrder Traversal
    cout << "InOrder Traversal (Print Order:- Left, Root, Right):-\n";
    InOrder_Traversal(root);

    // PreOrder traversal
    cout << "\nPreOrder Traversal (Print Order:- Root, Left, Right):-\n";
    PreOrder_Traversal(root);

    // PostOrder traversal
    cout << "\nPostOrder Traversal (Print Order:- Left, Right, Root):-\n";
    PostOrder_Traversal(root);

    // LevelOrder traversal
    cout << "\nLevel Traversal (Print Order:- Level 0, Level 1 and so on..):-\n";
    LevelOrder_Traversal(root);
}
