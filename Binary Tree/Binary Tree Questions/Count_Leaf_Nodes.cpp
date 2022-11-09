#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/* Function To Count Leaf Nodes */
/*
Approach:- Traverse the tree, While traversing check if the current nodes has no children it means it is a leaf node otherwise not.
*/
void InOrderTraversal(Node *root, int &count)
{
    // Base Case
    if(root == NULL){
        return;
    }

    // Recursive Case
    InOrderTraversal(root -> left, count);
    InOrderTraversal(root -> right, count);

    // If left and right both equals to NULL, means this is a leaf node ,increment the count.
    if(root -> left == NULL && root -> right == NULL){
        count++;
    }
}

int main()
{
    Node *root = NULL;
    /*
    Exmaple TestCases:-

    Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , Leaf Nodes = 3.
    view:-                      1                           level 0
                        3               5                   level 1
                    7      11       17      -1              level 2
                -1  -1  -1  -1   -1   -1                    level 3


    Ex 2:-  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1, Leaf Nodes = 3.
    view:-                          1                        level 0
                        2                   3                level 1
                    4       5           -1      6            level 2
                 -1  -1   7   -1             -1   -1         level 3
                       -1  -1                                level 4

    */

    // Building tree
    BinaryTree bt;
    bt.BuildTree_PreOrder(root);

    // count leaf node
    int count = 0;
    InOrderTraversal(root, count);
    cout<<count;
}