#include <bits/stdc++.h>
using namespace std;
/*
Approach:- Uisng MIN Heap.

Step 1:- Create MIN Heap.
Step 2:- saare k arrays ke 1st element ko MIN Heap me insert krdo.
Note:- after step 1, in saare k arrays ke 1st elements me se jo minimum element hoga vo heap.top() pe present hoga.
Step 3:- while(heap is not empty){
    Step 4:- minimum element ko ans vector me store krlo or pop krodo heap me se.
    Step 5:- saare k arraye ke next element ko heap me insert krdo.
}

Time Complexity:- O(n*k log(k))
Space Complexity:- O(n*k)

*/

class Node
{
public:
    int data; // element at i,j.
    int i;    // row index.
    int j;    // column index.

    // Constructor.
    Node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};

// custom comparator class.
class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        // compare on the basis of data.
        return a->data > b->data;
    }
};


vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Step 1:- create MIN Heap.
    priority_queue<Node *, vector<Node *>, Compare> minHeap;

    // Step 2:- saare k arrays ke 1st element ko MIN Heap me insert krdo.
    for (int i = 0; i < k; i++)
    {
        Node *firstElement = new Node(kArrays[i][0], i, 0);
        minHeap.push(firstElement);
    }

    // Note:- after step 1, in saare k arrays ke 1st elements me se jo minimum element hoga vo heap.top() pe present hoga.

    // Step 3;
    vector<int> ans;
    while (minHeap.size() > 0)
    {

        // Step 4:- store the minimum element in ans vector and pop it from heap.
        Node *temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        // step 5:- insert next elements of k arrays.
        int i = temp->i; // row index.
        int j = temp->j; // column index

        if (j + 1 < kArrays[i].size())
        {
            Node *next = new Node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }
    return ans;
}


int main()
{
    vector<vector<int>> Karrays = {
        {1},
        {2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12},
    };

    int k = Karrays.size();
    vector<int> ans = mergeKSortedArrays(Karrays, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}