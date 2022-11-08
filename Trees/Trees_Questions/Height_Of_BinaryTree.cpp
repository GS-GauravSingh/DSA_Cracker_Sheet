//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution
{
    /*
    Height of Binary Tree:- is the maximum levels we have in a tree.

    Approach 1:- traverse the tree using level order traversal and count the levels.

    height of binary tree = number of levels in a tree.

    Approach 2:- calculate the height of left subtree and right subtree,
    take the maximum of left and right and add 1 (root node).
    int ans = max(left, right) + 1; // +1 is for adding root node.

    */
    // Time and Space of Level Order Traversal is O(N).

    // Time Complexity:- O(N)
    // Space Complexity:- O(N)
    void LevelOrderTraversal(Node *root, int &height)
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL); // delimiter representing the end of current level.

        while (!q.empty())
        {
            Node *temp = q.front();
            if (temp == NULL)
            {
                height++;
                q.pop();

                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                q.pop();
                // push current level childrens if exists.
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

public:
    // Function to find the height of a binary tree.
    // using level Order Traversal
    int height1(struct Node *root)
    {
        // Base Cases
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }

        int height = 0;
        LevelOrderTraversal(root, height);
        return height;
    }

    // Approach 2:- code,
    // height of BT = max(heightOf(left Subtree), heightOf(right Subtree)) + 1; // +1 for adding root node.

    // Time Complexity:- O(N)
    // Space Complexity:- O(H), H is the height of the tree.

    
    int height2(struct Node *root)
    {
        // Base Cases
        if (root == NULL)
        {
            return 0;
        }

        // Recursive case

        // Calculating the height of left subtree
        int left = height(root->left);

        // Calculating the height of right subtree
        int right = height(root->right);

        // take the maximum of left and right subtree and add 1 for root node.
        int height = max(left, right) + 1;

        // return height
        return height;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.height1(root) << endl;
    }
    return 0;
}
// } Driver Code Ends