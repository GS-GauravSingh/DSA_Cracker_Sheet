#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Time Complexity:- O(N*H*H)
Space Complexity:- O(H), H is the height of the tree.
*/
void print(vector<int>& arr, int i)
{
    for (int j = i; j < arr.size(); j++)
        cout << arr[j] << " ";
    cout << endl;
}

void printKPaths(Node* root, vector<int>&path, int k){
    // Base Case
    if(root == NULL){
        return;
    }

    // add current node to path.
    path.push_back(root -> data);

    printKPaths(root -> left, path, k);
    printKPaths(root -> right, path, k);

    int sum = 0;
    int size = path.size();
    for (int i = size-1; i >= 0; i--)
    {
        sum+=path[i];

        if(sum == k){
            print(path, i);
        }
    }

    // Backtracking step.
    path.pop_back();
    
}


int main()
{
    /*
   Exmaple TestCases:-

   Ex 1:-  1 3 2 -1 -1 1 -1 -1 5 17 -1 -1 -1 , Height = 3.
   view:-                      1                           level 0
                       3               5                   level 1
                   2      11       17      -1              level 2
               -1  -1  -1  -1   -1   -1                    level 3


   Ex 2:-  1 2 7 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1, Height = 4.
   view:-                          1                        level 0
                       2                   3                level 1
                   7       5           -1      6            level 2
                -1  -1   7   -1             -1   -1         level 3
                      -1  -1                                level 4

   */

    // Building tree
    Node *root = NULL;
    BinaryTree bt;
    bt.BuildTree_PreOrder(root);

    vector<int> path;
    int k = 9;

    printKPaths(root, path,k);
    

    
}