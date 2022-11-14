/*
Question:-
Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction.


Example 1:

Input:
Tree =
          1
        /   \
       2     3
K = 3
Output: 2

Explanation:
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3
Example 2:

Input:
Tree =
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5
        /   / \     \
       1   1   2     6
K = 5
Output: 8

Explanation:
The following paths sum to K.
3 2
3 1 1
1 3 1
4 1
1 -1 4 1
-1 4 2
5
1 -1 5

Since the answer may be very large, compute it modulo 10^9 + 7.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of Tree)
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Approach:- find all the paths having sum equal to k.

Time Complexity:- O(N)
Space Complexity:- O(h), h is the height of the tree.
*/
void solve(Node *root, int k, int &count, vector<int> path)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }
    // Recursive Case

    // add current Node to path.
    path.push_back(root->data);

    // make a recursive call on left and right.
    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    // Backtracking step.

    // check if there is any value present in vector path that sum up to k.
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }

    // remove current node->data from vector, while returning back.
    path.pop_back();
}
int sumK(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
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

    int k = 10;
    cout<<sumK(root, k);
}