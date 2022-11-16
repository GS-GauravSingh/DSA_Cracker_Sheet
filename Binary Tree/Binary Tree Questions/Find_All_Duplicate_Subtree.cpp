#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Time Complexity:- O(N^2)  Since string copying takes O(n) extra time.
Space Complexity:- O(N^2) Since we are hashing a string for each node and length of this string can be of the order N.
*/

// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree

string solve(Node *root, vector<Node *> &ans, unordered_map<string, int> &mp)
{
    if (root == NULL)
    {
        return "N"; // seperator.
    }
    string s = to_string(root->data) + "_" + solve(root->left, ans, mp) + "_" + solve(root->right, ans, mp);
    mp[s]++;
    if (mp[s] == 2)
    {
        ans.push_back(root);
    }
    return s;
}

vector<Node *> printAllDups(Node *root)
{
    vector<Node *> ans;
    unordered_map<string, int> mp;
    solve(root, ans, mp);
    return ans;
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

    vector<Node *> ans = printAllDups(root);

    for(auto it:ans){
        bt.PreOrder_Traversal(it);
        cout<<endl;
    }
}

