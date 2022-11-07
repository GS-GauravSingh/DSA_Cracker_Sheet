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

void LevelOrder_BinaryTree_Build(Node *&root)
{
    queue<Node *> q;
    cout << "Enter Data for Root Node:-\n";
    int data;
    cin >> data;

    // making root node with given data.
    root = new Node(data);
    q.push(root); // push root into queue.

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter data for Left of " << temp->data << ":-\n";
        int dataForLeft;
        cin >> dataForLeft;
        if (dataForLeft != -1)
        {
            temp -> left = new Node(dataForLeft);
            q.push(temp -> left);
        }

        cout << "Enter data for Right of " << temp->data << ":-\n";
        int dataForRight;
        cin >> dataForRight;
        if (dataForRight != -1)
        {
            temp -> right = new Node(dataForRight);
            q.push(temp -> right);
        }
    }
}

/* Level Order Traversal */
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

int main()
{
    Node *root = NULL;

    // Level Order Build
    LevelOrder_BinaryTree_Build(root);

    // Level Order Traversal
    LevelOrder_Traversal(root);
}