/*
Question:-
Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.


Example 1:

Input:
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7

Explanation: If leaf with the value
8 is set on fire.
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.


Approach:-

For each node, we have to burn the left and right child node and parent node.
So, we have a pointer to left and right child, but we don't have any pointer to parent node. SO, first we need to store the parent node for each node.

Steps:-
1. create a mapping to store parent node of each node.
2. find target node.
3. start burning.

To start burning you need 2 additional data structure:-
1. map to track if node is visited or not.
2. queue to traverse with target node.

Time Complexity:- O(N log n)
Space Complexity:- O(height of tree)
*/

#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

// create mapping.
// return target node.
Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    Node *res = NULL;

    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = NULL; // there is no parent of root node.

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            // finding target node.
            res = front;
        }

        // update map and push left and right child.
        if (front->left != NULL)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
{
    map<Node *, bool> visited;
    queue<Node *> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;

    while (!q.empty())
    {
        bool flag = false;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            // process neighbouring node.
            Node *front = q.front();
            q.pop();

            // left
            if (front->left != NULL && visited[front->left] != true)
            {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }

            // right
            if (front->right != NULL && visited[front->right] != true)
            {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }

            // parent
            Node *parent = nodeToParent[front];
            if (parent != NULL && visited[parent] != true)
            {
                flag = true;
                q.push(parent);
                visited[parent] = true;
            }
        }

        if (flag == true)
        {
            ans++;
        }
    }
    return ans;
}

int minTime(Node *root, int target)
{
    // algo:-
    //  Step 1:- create node to parent mapping.
    //  Step 2:- find target node.
    //  Step 3:- start burning.

    int ans = 0;
    map<Node *, Node *> nodeToParent;
    Node *targetNode = createParentMapping(root, target, nodeToParent);

    ans = burnTree(targetNode, nodeToParent);
    return ans;
}

int main()
{
    /*
  Exmaple TestCases:-

  Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 18 19 -1 -1 -1 -1 -1, Not Balanced
  view:-                      1                           level 0
                      3               5                   level 1
                  7      11       17      -1              level 2
              -1  -1  -1  -1   18   -1                    level 3
                             19   -1
                          -1   -1


  Ex 2:-  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1, Balanced
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

    int target = 7;
    cout<<minTime(root, target)<<endl;
}