#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;
/*
Time Comlexity:- O(n)
Space Comlexity:- O(n)
*/

Node *string_2_tree(string &str, int &start)
{
    // Base Case
    if (start >= str.length())
    {
        return NULL;
    }

    // extract number from string.

    // to check if number if -ve or not.
    bool neg = false;
    if (str[start] == '-')
    {
        neg = true;
        start++;
    }

    // extracting number from string.
    int num = 0;
    // just in case, a numbers is having more then one digits.
    while (start < str.length() && str[start] >= '0' && str[start] <= '9')
    {
        num = num * 10;
        num = num + (str[start] - '0');
        start++;
    }

    // if number is negative.
    if (neg == true)
    {
        num = -num;
    }

    // creating root node.
    Node *root = new Node(num);

    // after creating root node, start >= str.length(), return root node.
    if (start >= str.length())
    {
        return root;
    }

    // Now, if str[start] == '(', first create it's left node, and if left node already exist's then create it's right node.
    if (start < str.length() && str[start] == '(')
    {
        start++;
        root->left = string_2_tree(str, start);
    }

    // if str[start] == ')', in that case, return from here, we've to create right node of previous root.
    if (start < str.length() && str[start] == ')')
    {
        start++;
        return root;
    }

    // if str[start] == '(', now create it's right subtree.
    if (start < str.length() && str[start] == '(')
    {
        start++;
        root -> right = string_2_tree(str, start);
    }

    // if str[start] == ')', return from here.
    if (start < str.length() && str[start] == ')')
    {
        start++;
        return root;
    }

    return root;
}

int main()
{
    string expression = "4(2(3)(1))(6(5))";
    int startIndex = 0;

    Node* root = string_2_tree(expression, startIndex);
    BinaryTree bt;
    bt.PreOrder_Traversal(root);
}