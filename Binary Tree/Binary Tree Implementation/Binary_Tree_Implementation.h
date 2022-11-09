/*

Binary Tree:- A tree is called Binary Tress, if each node has 0 child, 1 child or 2 child. Empty tree is also a valid binary tree.

In Short:-
Binary Tree => each node has <= 2 child.


There are 4 common ways of traversing the nodes of a Binary Tree, namely:
1. In order Traversal (Left, Root, Right)
2. Pre Order Traversal (Root, Left, Right).
3. Post Order Traversal (Left, Right, Root)
4. Level Order Traversal (Level Wise Traversing).

Complexities :-

1. InOrder Traversal :-
Time Complexity:- O(n)
Space Complexity:- O(h), h is the height of the tree.

2. PreOrder Traversal :-
Time Complexity:- O(n)
Space Complexity:- O(h), h is the height of the tree.

3. PostOrder Traversal :-
Time Complexity:- O(n)
Space Complexity:- O(h), h is the height of the tree.

4. LevelOrder Traversal :-
Time Complexity:- O(n)
Space Complexity:- O(n), n is the size of queue.

*/

// forward decleration of Binary Tree class
class BinaryTree;

#include <bits/stdc++.h>
using namespace std;

/* Node Structure for Binary Tree */
class Node
{
private:
public:
    /* Data Members */
    int data;
    Node *left;
    Node *right;
    /*  Constructor  */
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }

};

/*  Binary Tree Class */
class BinaryTree
{
private:
public:
    /*
    1st Recursive Method To Build Binary Tree:-

    PreOrder Build :- In PreOrder Build, First we build the root node, then we build the left nodes, and then we build the right nodes, this way of building tree is know as Pre-order Build.

    PreOrder Build :- Order (Root, Left, Right).
    */

    Node *BuildTree_PreOrder(Node *&root)
    {
        // getting data for node.
        cout << "Enter Data for Node:-\n";
        int data;
        cin >> data;
        // creating node with give data.
        root = new Node(data);

        // -1 represents NULL
        if (data == -1)
        {
            return NULL;
        }

        // insert data for left.
        cout << "Enter data for inserting at left of " << root->data << ":-\n";
        root->left = BuildTree_PreOrder(root->left); // making a recursive call for left side.

        // insert data at right.
        cout << "Enter data for inserting at right of " << root->data << ":-\n";
        root->right = BuildTree_PreOrder(root->right); // making a recursive call for right side.

        return root;
    }

    /*
    2nd Recursive Method To Build Binary Tree:-  Level Order Build
    */

    void BuildTree_LevelOrder(Node *&root)
    {
        queue<Node *> q;
        // getting data for creating root node.
        cout << "Enter Data for root Node:-\n";
        int dataForRoot;
        cin >> dataForRoot;

        // creating root node with given data.
        root = new Node(dataForRoot);

        // push root into queue.
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            cout << "Enter data for Left of " << curr->data << ":-\n";
            int dataForLeft;
            cin >> dataForLeft;
            if (dataForLeft != -1)
            {
                curr->left = new Node(dataForLeft);
                q.push(curr->left);
            }

            cout << "Enter data for Right of " << curr->data << ":-\n";
            int dataForRight;
            cin >> dataForRight;
            if (dataForRight != -1)
            {
                curr->right = new Node(dataForRight);
                q.push(curr->right);
            }
        }
    }

    /* -------------------------- All Traversals ------------------ */

    /* InOrder Traversal (Left, Root, Right) :- Recursive function for printing Tree.
        Time Complexity:- O(n)
        Space Complexity:- O(h), h is the height of the tree.
    */
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

    /* PreOrder Traversal (Root, Left, Right) :- Recursive function for printing Tree.

    Time Complexity:- O(n)
    Space Complexity:- O(h), h is the height of the tree.

    */
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

    /* PostOrder Traversal :- Recursive function for printing Tree.

    Time Complexity:- O(n)
    Space Complexity:- O(h), h is the height of the tree.


    */
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
    /*

    LevelOrder Traversal also Known as Breadth First Search (BFS),Level order traversal means print in levels, It means first we need to print the root node present at level 0, then we need to print all elements present at level 1, then level 2, level 3 asn so on.

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

    Time Complexity:- O(n)
    Space Complexity:- O(n), n is the size of queue.
    */

    void LevelOrder_Traversal(Node *&root)
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
};
