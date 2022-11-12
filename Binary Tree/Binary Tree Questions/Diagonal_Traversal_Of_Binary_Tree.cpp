/*
Question:-
Given a Binary Tree, print the diagonal traversal of the binary tree.
Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4



Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

void solve(Node *root, map<int, vector<int>> &mpp, int pos)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // push data into map.
    mpp[pos].push_back(root->data);

    // while going toward left, increment the position.
    solve(root->left, mpp, pos + 1);

    // move towards right.
    solve(root->right, mpp, pos);
}

vector<int> diagonal(Node *root)
{
    // map is used to store diagonal elements;
    map<int, vector<int>> mpp;
    solve(root, mpp, 0);

    // extract the values from map and store it in answer vector.
    vector<int> ans;
    for (auto i : mpp)
    {
        for (auto j : i.second)
        {
            ans.push_back(j);
        }
    }
    return ans;
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

    // Top View
    vector<int> ans = diagonal(root);
    print(ans);
}