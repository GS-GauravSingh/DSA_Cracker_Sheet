#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;
/*
Approach :- 
declare a stack of node.
declare a vector of int to store answer.
Run a infinite loop while(1), and iside this loop do the following steps,

if (root is != NULL){
    push(root) into stack;
    and move to the left side (root -> left);
}
else{
    // if root == NULL,
    check if stack is empty or not, if ues break the loop all element will be traversed.
    if(s.empty() == true){
        break the loop;
    }

    // if stack is not empty.

    update the root with stack.top();
    pop the top element of stack.
    store/print root -> data;
    move toward the right (root -> right). 
}

*/

// Inorder Traversal :- Left, Root, Right
// Time Complexity:- O(n) 
// Space Complexity:- O(n)
void Iterative_Inorder_Traversal(Node *root)
{
    stack<Node *> s;
    vector<int> inOrder; // to store answer.

    while (true)
    {
        if(root != NULL){
            s.push(root);
            root = root -> left;
        }
        else{
            if(s.empty() == true){
                break;
            }

            root = s.top();
            s.pop();
            inOrder.push_back(root -> data);
            root = root -> right;
        }
    }

    // print answer
    cout<<"Inorder Traversal (Left, Root, Right):-\n";
    for (int i = 0; i < inOrder.size(); i++)
    {
        cout<<inOrder[i]<<" ";
    }
    
    
}

int main()
{
    /*
    Exmaple TestCases:-

    Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 ,
    view:-                      1                           level 0
                        3               5                   level 1
                    7      11       17      -1              level 2
                -1  -1  -1  -1   -1   -1                    level 3


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

    Iterative_Inorder_Traversal(root);
}