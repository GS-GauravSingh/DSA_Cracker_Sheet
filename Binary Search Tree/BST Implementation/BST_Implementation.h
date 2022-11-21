/*
BST = node values at Root -> left < Root value and node values at Root -> right > Root value.
So , for every node if this property is statisfied then this tree is considered as Binary Search Tree (BST).

Property:- InOrder Traversal of Binary Search Tree (BST) comes out to be in sorted order.
*/

/*
Time and Space Complexity of Operation on BST:-

                Avg. case       worst case(skewed tree)
Searching:-        O(h)                 O(n)
Insertion:-        O(h)                 O(n)
Deletion:-         O(h)                 O(n)
*/

#include <bits/stdc++.h>
using namespace std;

/* Node Structure for BST */
class Node
{
private:
public:
    int data;
    Node *left;
    Node *right;
    // Constructor.
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/*  Binary Search Tree Class */
class BinarySearchTree
{
private:
    /* Method to insert data into BST */
    Node *insertIntoBST(Node *root, int data)
    {
        // Base Case
        if (root == NULL)
        {
            // if root == NULL, create a root with give data and return.
            root = new Node(data);
            return root;
        }

        // Recursive Case

        // For Insertion check,
        // if data < root value, insert at left.
        // else data > root value, insert at right.
        if (data < root->data)
        {
            root->left = insertIntoBST(root->left, data);
        }
        else
        {
            root->right = insertIntoBST(root->right, data);
        }
    }

    /* Function to find minimum value in BST,    
    This function is used in deletion from bst code.
    */
    int findMinimum(Node *root)
    {
        // we know that in case of BST, the minimum value is present at the leftmost node in the BST.

        // Base Case
        if (root == NULL)
        {
            return -1;
        }

        Node *curr = root;
        while (curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr->data;
    }

public:
    // Methods,

    /* Method to take input and insert into BST */
    void takeInput(Node *&root)
    {
        cout << "Enter data to insert into BST:-\n";
        cout << "-1 Represents NULL.\n";

        int data;
        while (true)
        {
            cin >> data;

            // -1 is used to break the loop.
            if (data == -1)
            {
                break;
            }

            // insert data into BST.
            root = insertIntoBST(root, data);
        }
    }

    /* Method to delete a node with given value from BST */
    /*
    Algorithm:-
    Step 1:- find node that we have to delete.
    Step 2:- So, to delete that node we have 4 cases,
        case 1:- the node which we have to delete have 0 child nodes (leaf node). In this case just delete that node and return NULL.
        case 2:- the node which we have to delete have 1 child nodes. In this case just delete the node and return the child node.
        case 3:- the node which we have to delete have 1 child nodes. In this case just delete the node and return the child node.
        case 4:- the node which we have to delete have 2 child nodes. In this case we have to options:-

                Option 1st:- find the maximum value from left subtree and replace that value of this node value, and delete that value from left subtree.

                Option 2nd:- find the minimum value from right subtree and replace that value of this node value, and delete that value from right subtree.

                => You can use any one option of your choice.
    */
    Node *deleteFromBST(Node *root, int val)
    {
        // Base Case
        if (root == NULL)
        {
            return root;
        }

        if (root->data == val)
        {
            // case 1:- leaf node.
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            // case 2:- node has 1 child.
            // if left child exists and no right child.
            if (root->left != NULL && root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // if right child exists and no left child.
            if (root->left == NULL && root->right != NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }

            // case 3:- node has 2 child.
            if (root->left != NULL && root->right != NULL)
            {
                // in this case we have to options:-
                // option 1st:- find the maximum value from left subtree and replace that value of this node value, and delete that value from left subtree.

                // option 2nd:- find the minimum value from right subtree and replace that value of this node value, and delete that value from right subtree.

                // you can use any one option of your choice.
                // I am using option 2nd.

                // get the minimum value from right subtree.
                int minValue = findMinimum(root->right);

                // replace that minimum value from the node which we have to delete.
                root->data = minValue;

                // delete that minimum value from the right subtree.
                root->right = deleteFromBST(root->right, minValue);
            }
        }
        else if (root->data > val)
        {
            root->left = deleteFromBST(root->left, val);
        }
        else
        {
            root->right = deleteFromBST(root->right, val);
        }
    }

    // Traversal's Code,

    // InOrder Traversal:- Left, Root, Right.
    // Time Complexity:- O(n)
    // Space Complexity:- O(n)
    void InOrderTraversal(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }

        // Recursive Case
        InOrderTraversal(root->left);
        cout << root->data << " ";
        InOrderTraversal(root->right);
    }

    // PreOrder Traversal:- Root, Left, Right.
    // Time Complexity:- O(n)
    // Space Complexity:- O(n)
    void PreOrderTraversal(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }

        // Recursive Case
        cout << root->data << " ";
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }

    // PostOrder Traversal:- Left, Right, Root.
    // Time Complexity:- O(n)
    // Space Complexity:- O(n)
    void PostOrderTraversal(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }

        // Recursive Case
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        cout << root->data << " ";
    }

    // LevelOrder Traversal:- level wise (left to right).
    // Time Complexity:- O(n)
    // Space Complexity:- O(n)
    void LevelOrderTraversal(Node *&root)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }

        queue<Node *> q;
        q.push(root);
        q.push(NULL); // delimiter representing the end of current level.

        // Remember at the end of any level, our queue will contain childrens of current level if present.
        // So, whenever you pop out NULL, push another NULL, but the corner case is when the current level has no childrens, in that case when you pop out NULL our queue is empty then there is no need to push another NULL.

        while (!q.empty())
        {
            Node *temp = q.front();
            if (temp == NULL)
            {
                // temp == NULL, means current level is end and our queue will contains childrens of nodes present at current level.
                cout << "\n";
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

                // push left and right child into queue if exist's.
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
