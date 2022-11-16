#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;
/*
Time Complexity:- O(N^2)  Since string copying takes O(n) extra time.
Space Complexity:- O(N^2) Since we are hashing a string for each node and length of this string can be of the order N.
*/

/*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/

unordered_map<string, int> m;
string solve(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return "$"; // seperator.
    }

    string s = "";
    if (root->left == NULL && root->right == NULL)
    {
        s = to_string(root->data);
        return s;
    }

    s = s + to_string(root->data);
    s = s + " " + solve(root->left);
    s = s + " " + solve(root->right);
    m[s]++;
    return s;
}
int dupSub(Node *root)
{

    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    solve(root);

    for (auto it : m)
    {
        if (it.second >= 2)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    // Building tree.
    Node *root = NULL;
    BinaryTree bt;
    bt.BuildTree_PreOrder(root);

    cout<<dupSub(root);
}