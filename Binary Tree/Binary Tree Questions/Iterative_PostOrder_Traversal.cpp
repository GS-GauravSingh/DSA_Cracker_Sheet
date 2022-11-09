#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

// PostOrder Traversal :- Left, Right, Root
// Time Complexity:- O(2*n)
// Space Complexity:- O(n)
void Iterative_PostOrder_Traversal(Node *root)
{
    // Base Case,
    // if root == NULL, simply return from here.
    if (root == NULL)
    {
        return;
    }

    vector<int> PostOrder; // to store answer.
    stack<Node *> s;       // we're going to use stack data structure.

    while (root != NULL || !s.empty())
    {
        if (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            Node *temp = s.top()->right;
            if (temp == NULL)
            {
                temp = s.top();
                s.pop();
                PostOrder.push_back(temp->data);

                while (!s.empty() && temp == s.top()->right)
                {
                    temp = s.top();
                    s.pop();
                    PostOrder.push_back(temp->data);
                }
            }
            else
            {
                root = temp;
            }
        }
    }

    // print answer
    cout << "PostOrder Traversal (Left, Right, Root):-\n";
    for (int i = 0; i < PostOrder.size(); i++)
    {
        cout << PostOrder[i] << " ";
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

    Iterative_PostOrder_Traversal(root);
}