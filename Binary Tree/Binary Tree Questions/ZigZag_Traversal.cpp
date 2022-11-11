/*

Question:-
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Example 1:

Input:
        1
      /   \
     2     3
    / \   /  \
   4   5 6    7
Output:

1 3 2 4 5 6 7

Explanation:-
level 0 (left to right) :-  1
level 1 (right to left) :-  3 2
level 2 (left to right) :-  4 5 6 7

*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/* Zig Zag Traversal Method */

// Time Complexity:- O(n)
// Space Complexity:- O(n)

vector<int> zigZagTraversal(Node *root)
{
    // Base Case
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }

    queue<Node *> q;
    q.push(root);
    int LeftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        // Processing Level
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            // Imp. Step.
            // normal or reverse insert.
            int indexToInsert = LeftToRight ? i : size - i - 1;
            ans[indexToInsert] = frontNode->data;

            // push left and right child
            if (frontNode->left != NULL)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right != NULL)
            {
                q.push(frontNode->right);
            }
        }

        // change the direction
        LeftToRight = !LeftToRight;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

/* Method to print vector */
void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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

    // zig zag traversal
    vector<int> ans;
    ans = zigZagTraversal(root);
    print(ans);
}