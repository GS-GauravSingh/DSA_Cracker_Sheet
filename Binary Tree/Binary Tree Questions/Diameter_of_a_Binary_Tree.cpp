/*

Diameter of Tree = number of nodes in the longest path b/w any two end nodes. Where end Node can be your leaf node or root node.
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

*/

/*
Approach 1:-

You can find diameter in 3 ways.

1. It may possible that the answer(longest route) is from left subtree.
2. or It may possible that the answer(longest route) is from right subtree.
3.  or It may possible that the answer(longest route) is from left and right subtree.

Time Complexity: O(n^2)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

// Approach 1:- seperately calculating height.
// Time Complexity: O(n^2)
// Space Complexity: O(n)

int height(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    // Recursive Case

    // calculating the height of left subtree.
    int left = height(root -> left);

    // calculating the height of right subtree.
    int right = height(root -> right);

    // Overall height = max(left, right) + 1; // +1 for height of root node.
    int height =  max(left, right) + 1;

    // return height;
    return height;
}

int diameter(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    // Recursive Case

    // 1st option. ans(longes route) is from left subtree.
    int left = diameter(root->left);

    // 2nd option. ans(longes route) is from right subtree.
    int right = diameter(root->right);

    // 3rd option. ans(longes route) is from both left and right subtree.
    // in that case you need to find the height of left and right subtree.
    int Left_And_Right = height(root->left) + height(root->right) + 1;
    // +1 is for adding the height of root node.

    // take the longest route
    int longestRoute = max(left, max(right, Left_And_Right));

    // return longest route;
    return longestRoute;
}



// Approach 2:- calculating height in same function.
// Time Complexity: O(n)
// Space Complexity: O(n)

// using pair, first block of pair is used for returning diameter.
// second block of pair is used ofr returning height.
pair<int, int> diameter_Fast(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        // if root == NULL, diameter = 0 and height = 0.
        return {0,0};
    }

    // Recursive Case

    // 1st option. ans(longes route) is from left subtree.
    pair<int, int> left = diameter_Fast(root->left);

    // 2nd option. ans(longes route) is from right subtree.
    pair<int, int> right = diameter_Fast(root->right);

    // getting diameter of left subtree.
    int leftAns = left.first;

    // getting diameter of right subtree.
    int rightAns = right.first;

    // 3rd option. ans(longes route) is from both left and right subtree.
    // in that case you need to find the height of left and right subtree.
    int left_And_right = left.second + right.second + 1;
    // +1 is for adding the height of root node.

    // pair to store answer.
    pair<int, int> ans;

    // take the longest route
    ans.first = max(leftAns, max(rightAns, left_And_right));

    // canculating and store the height.
    ans.second = max(left.second, right.second) + 1;

    // return longest route;
    return ans;
}

int main()
{
    /*
   Exmaple TestCases:-

   Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , diameter = 5.
   view:-                      1                           level 0
                       3               5                   level 1
                   7      11       17      -1              level 2
               -1  -1  -1  -1   -1   -1                    level 3


   Ex 2:-  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1, diameter = 6.
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

    // diameter
    cout<<diameter(root)<<endl;

    // diameter fast
    cout<<diameter_Fast(root).first<<endl;
}