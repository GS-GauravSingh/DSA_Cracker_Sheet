/*

Diameter of Tree = number of nodes in the longest path b/w any two nodes.
Ex:-
Input:-
       1
     /  \
    2    3

Output: 3

Explanation:-
Longest Path :- 3 -> 1 -> 2 or 2 -> 1 -> 3
Diameter = no. of nodes in longest path = 3;

Ex:-
Input:-
         10
        /   \
      20    30
    /   \
   40   60

Output: 4

Explanation:-
Longest Path :- 30 -> 10 -> 20 -> 40 or 40 -> 20 -> 10 -> 40
Diameter = no. of nodes in longest path = 4;

Note:- End Node can be your leaf node or root node.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
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
    Node *root = newNode(stoi(ip[0]));

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

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution
{
    /*
    Approach 1:-

    You can find diameter in 3 ways.

    1. It may possible that the answer(longest route) is from left subtree.
    2. or It may possible that the answer(longest route) is from right subtree.
    3.  or It may possible that the answer(longest route) is from left and right subtree.

    Time Complexity: O(n^2)
    Space Complexity: O(n)
    */

    int height(struct Node *root)
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

public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return 0;
        }

        // Recursive Case
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + height(root->right) + 1;

        int ans = max(op1, max(op2, op3));
        return ans;
    }

    //Approach 2:- code
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    // first block of pair is used for diameter.
    // second block of pair is used for height.
    pair<int, int> diameter_Fast(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return {0,0};
        }

        // Recursive Case
        pair<int, int> left = diameter_Fast(root -> left);
        pair<int, int> right = diameter_Fast(root -> right);

        // diameter calculation
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

         
        // pair<int, int> ans; first block = diameter, second block = height.
        pair<int, int> ans;
        // maximum diameter calculation.
        ans.first = max(op1, max(op2, op3));
        // height calculation
        ans.second = max(left.second , right.second) + 1;
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}

// } Driver Code Ends