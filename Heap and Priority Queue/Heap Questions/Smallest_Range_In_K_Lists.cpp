#include <bits/stdc++.h>
using namespace std;

/*
Approach :- Using MIN Heap.

Time Complexity:- O() 
Space Complexity:- O()
*/

class Node
{
public:
    int data;
    int i; // row index.
    int j; // column index.

    // Constructor
    Node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    // Step 1:- create MIN Heap.
    priority_queue<Node *, vector<Node *>, Compare> minHeap;

    // variable to calculate minimum and maximum range.
    int mini = INT_MAX;
    int maxi = INT_MIN;

    // Step 2:- saare k list ke first element ko MIN Heap me insert krdo and minimum element push krte time maximum element ko trak krna.
    for (int i = 0; i < k; i++)
    {
        int element = a[i][0];

        // tracking minimum and maximum element.
        mini = min(mini, element);
        maxi = max(maxi, element);

        // push element into heap.
        minHeap.push(new Node(element, i, 0));
    }
    
    // variable to store final range.
    int start = mini, end = maxi;

    // Step 4:- repeate the given step while heap is not empty.
    while (!minHeap.empty())
    {
        

        // step 4.1:- extract minimum element form heap.
        Node *temp = minHeap.top();

        // step 4.2:- pop it from heap.
        minHeap.pop();

        // step 4.3:- update minimum range.
        mini = temp->data;

        // step 4.4:- update final range.
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // step 4.5:- if next element exist's, then update maxi and push it into heap.
        if (temp->j + 1 < n)
        {
            maxi = max(maxi, a[temp->i][temp->j + 1]);
            minHeap.push(new Node(a[temp->i][temp->j + 1], temp->i, temp->j + 1));
        }

        // step 4.6:- if next element does not exist's, then break the loop.
        else
        {
            break;
        }
    }

    // our answer will be (end - start + 1).
    return (end - start + 1);
}


int main()
{
}