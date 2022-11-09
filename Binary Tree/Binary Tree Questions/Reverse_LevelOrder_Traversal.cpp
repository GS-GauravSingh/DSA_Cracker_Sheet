#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

// Time and Space Complexity = O(n)

void Reverse_LevelOrder_Traversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // delimiter representing the end of level 0.

    // vector to store ans;
    vector<int> ans;

    // Remember at the end of any level, our queue will contain childrens of current level if present.
    // So, whenever you pop out NULL, push another NULL, but the corner case is when the current level has no childrens, in that case when you pop out NULL our queue is empty then there is no need to push another NULL.

    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp == NULL)
        {
            // temp == NULL, means current level is end and our queue will contains childrens of nodes present at current level.
            q.pop();

            // Inserting a new NULL for next level.
            if (!q.empty())
            { 
                ans.push_back(-1); // -1 used while printing ans.
                q.push(NULL);
            }
        }
        else
        {
            // pop it.
            q.pop();
            // print the data.
            ans.push_back(temp->data);

            // first push right child if exist.
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }

            // then push left child if exist.
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

        }
    }

    // reverse the answer vector.
    reverse(ans.begin(), ans.end());
    

    // print the answer vector.
    for (int i = 0; i < ans.size(); i++)
    {
        if(ans[i] == -1){
            cout<<endl;
        }
        else{
            cout<<ans[i]<<" ";
        }

    }
    
}

int main()
{
    // Building tree
    Node *root = NULL;
    BinaryTree bt;
    bt.BuildTree_PreOrder(root);

    /*
    Exmaple TestCases:-

    Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , Leaf Nodes = 3.
    view:-                      1                           level 0
                        3               5                   level 1
                    7      11       17      -1              level 2
                -1  -1  -1  -1   -1   -1                    level 3


    Ex 2:-  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1, Leaf Nodes = 3.
    view:-                          1                        level 0
                        2                   3                level 1
                    4       5           -1      6            level 2
                 -1  -1   7   -1             -1   -1         level 3
                       -1  -1                                level 4

    */

    cout << "Before Reverse:-\n";
    bt.LevelOrder_Traversal(root);

    cout << "After Reverse:-\n";
    Reverse_LevelOrder_Traversal(root);
}