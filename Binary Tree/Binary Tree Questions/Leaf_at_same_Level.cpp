#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Time Complexity:- O(n).
Space Complexity:- O(n) for call stack
*/


int levelOfLeaf = -1;
bool solve(Node *root, int level)
{
    // Base Case
    if (root == NULL)
    {
        return true;
    }
    // if it is a leaf node.
    if (root->left == NULL && root->right == NULL)
    {

        // store level of leaf
        if (levelOfLeaf == -1)
        {
            levelOfLeaf = level;
            return true;
        }

        // if levelOfLeaf != -1, means,
        // in past we already visited a leaf node and we have the level of that leaf node.

        // So, check if the current level of leaf node is same as the the leaf node we had visited in past.
        // if yes, return true;
        // else return false;

        if (levelOfLeaf == level)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Recursive Case
    bool left = solve(root->left, level + 1);
    bool right = solve(root->right, level + 1);

    if (left == true && right == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool check(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return true;
    }

    int level = 0;
    return solve(root, level);
}

int main()
{
    /*
  Exmaple TestCases:-

  Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 18 19 -1 -1 -1 -1 -1,
  view:-                      1                           level 0
                      3               5                   level 1
                  7      11       17      -1              level 2
              -1  -1  -1  -1   18   -1                    level 3
                             19   -1
                          -1   -1


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

    cout<<check(root);
}