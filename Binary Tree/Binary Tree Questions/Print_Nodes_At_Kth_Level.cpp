#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

// Print Nodes present at Kth level in a binary tree. 
// Time and Space O(n).
vector<int> printKthLevel(Node *root, int k)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    int reach = 0;
    vector<int> ans;
    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp == NULL)
        {
            reach++;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();

            // when we reach the kth level, store the answer.
            if (reach == k)
            {
                ans.push_back(temp->data);
            }

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
    return ans;
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

    int k = 2;
    vector<int> ans = printKthLevel(root, 2);
    for(int i:ans){
        cout<<i<<" ";
    }
}