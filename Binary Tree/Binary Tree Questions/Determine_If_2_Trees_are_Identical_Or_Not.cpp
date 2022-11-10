/*
Question:- Given two binary trees, the task is to find if both of them are identical or not.

Example 1:

Input:
     1          1
   /   \      /   \
  2     3    2     3

Output: Yes

Explanation: There are two trees both
having 3 nodes and 2 edges, both trees
are identical having the root as 1,
left child of 1 is 2 and right child
of 1 is 3.

Example 2:

Input:
    1       1
  /  \     /  \
 2    3   3    2

Output: No

Explanation: There are two trees both
having 3 nodes and 2 edges, but both
trees are not identical.
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

// Function to check if two trees are identical.
// Time Complexity:- O(n)
// Space Complexity:- O(n)
bool isIdentical(Node *r1, Node *r2)
{
    // Base Cases
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }

    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }

    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    // Recursive Case
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool compareValue = r1->data == r2->data;

    if (left && right && compareValue)
    {
        return true;
    }
    return false;
}

int main()
{   
    /*
    Ex 1:-
    1st tree :- 1 2 -1 -1 3 -1 -1
    view:-            1
                2           3
            -1    -1     -1   -1

    
    2nd tree:- 1 2 -1 -1 3 -1 -1
    view:-            1
                2           3
            -1    -1     -1   -1


    Ex 2:-
    1st tree :- 1 2 -1 -1 3 -1 -1
    view:-            1
                2           3
            -1    -1     -1   -1

    
    2nd tree:- 1 3 -1 -1 2 -1 -1
    view:-            1
                3           2
            -1    -1     -1   -1

    */

    // Building tree
    Node *root1 = NULL;
    Node *root2 = NULL;
    BinaryTree bt;
    cout<<"Enter data for 1st Binary tree:-\n";
    bt.BuildTree_PreOrder(root1);

    cout<<"\nEnter data for 2nd Binary tree:-\n";
    bt.BuildTree_PreOrder(root2);


    cout<<isIdentical(root1, root2);
}