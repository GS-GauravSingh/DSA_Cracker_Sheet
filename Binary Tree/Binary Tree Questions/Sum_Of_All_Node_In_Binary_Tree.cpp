#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

// Function that returns sum of all nodes in Binary tree.
// Time and Space O(n).
int Sum_Of_All_Nodes(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    // Recursive Case

    // calculating the sum of left subtree.
    int left = Sum_Of_All_Nodes(root->left);

    // calculating the sum of right subtree.
    int right = Sum_Of_All_Nodes(root->right);

    // Overall summation = left + right + root -> data
    int sum = left + right + root->data;

    // return sum.
    return sum;
}

int main()
{
    /*
   Exmaple TestCases:-

   Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , Height = 3.
   view:-                      1                           level 0
                       3               5                   level 1
                   7      11       17      -1              level 2
               -1  -1  -1  -1   -1   -1                    level 3


   Ex 2:-  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1, Height = 4.
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

    // sum of al node in BT.
    cout<<Sum_Of_All_Nodes(root);
}