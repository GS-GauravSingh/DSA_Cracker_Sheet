#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

// PreOrder Traversal :- Root, Left, Right
// Time Complexity:- O(n)
// Space Complexity:- O(n)
void Iterative_PreOrder_Traversal(Node *root)
{
    // Base Case,
    // if root == NULL, simply return from here.
    if (root == NULL)
    {
        return;
    }

    vector<int> PreOrder; // to store answer.
    stack<Node *> s;// we're going to use stack data structure.
    s.push(root); //push root into stack.

    while (!s.empty())
    {
        root = s.top();
        s.pop();
        PreOrder.push_back(root->data);

        // first push the right child.
        if (root->right != NULL)
        {
            s.push(root->right);
        }

        // then push the left child.
        if (root->left != NULL)
        {
            s.push(root->left);
        }
    }

    // print answer
    cout << "PreOrder Traversal (Root, Left, Right):-\n";
    for (int i = 0; i < PreOrder.size(); i++)
    {
        cout << PreOrder[i] << " ";
    }
}

int main()
{
    /*
    Exmaple TestCases:-

    Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 ,
    view:-                      1                           level 0
                        3               5                   level 1
                    7      11       17      -1              level 2
                -1  -1  -1  -1   -1   -1                    level 3


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

    Iterative_PreOrder_Traversal(root);
}