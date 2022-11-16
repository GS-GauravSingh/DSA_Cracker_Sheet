#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Time Complexity:- The solution does a traversal of both trees. 
So time complexity is O(min(m,n)*2) or O(min(m,n)) where m and n are number of nodes in given trees.

Space Complexity:- O(n)
*/

// Return True if the given trees are isomotphic. Else return False.
bool isIsomorphic(Node *root1, Node *root2)
{
    // Base Cases
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return true;
    }

    if (root1->data != root2->data)
    {
        return false;
    }

    // Recursive Case
    bool a = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
    bool b = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);

    return a || b;
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
    Node *root1 = NULL;
    Node *root2 = NULL;
    BinaryTree bt;
    bt.BuildTree_PreOrder(root1);
    bt.BuildTree_PreOrder(root2);

    cout<<isIsomorphic(root1, root2);
}