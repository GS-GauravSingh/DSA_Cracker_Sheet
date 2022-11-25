#include <bits/stdc++.h>
using namespace std;

class MIN_Heap
{
private:
    vector<int> arr;

public:
    // Constructor.
    MIN_Heap(int default_size = 10)
    {
        arr.reserve(default_size);
        arr.push_back(-1);

        cout << "This is MIN Heap Implementation.\n";
    }

    // Methods,

    /* Method to push element into Heap. Time Complexity of insertion:- O(log(n)) */
    void push(int element)
    {
        // step 1:- simply insert data at the end of our vector/array.
        arr.push_back(element);

        // step 2:- place inserted value to its correct position in vector.
        int insertedValueIdx = arr.size() - 1;

        while (insertedValueIdx > 1)
        {
            int parentNodeIdx = insertedValueIdx / 2; // in 1-based indexing, parent node of value inserted at ith index is present at index (i/2).

            // as we're inplementing MIN Heap,
            // value of root node is always <= it's child node.
            if (arr[parentNodeIdx] > arr[insertedValueIdx])
            {
                // if parent node value is greater than it's child node then swap it.
                swap(arr[parentNodeIdx], arr[insertedValueIdx]);
                insertedValueIdx = parentNodeIdx;
            }
            else
            {
                return;
            }
        }
    }

    /* Method to pop root element from Heap. Time Complexity of deletion:- O(log(n)) */
    void pop()
    {

        // Base Case
        if (arr.size() == 1)
        {
            cout << "Nothing to delete, Heap is empty.\n";
        }

        // Step 1:- replace or swap or put the value of last node with the root node.
        int lastElement = arr.back();
        arr[1] = lastElement;

        // Step 2:- remove last node.
        arr.pop_back();

        // Step 3:- place root node to its correct position.
        int rootIdx = 1; // root node index.
        while (rootIdx < arr.size())
        {
            // find indexes of it's child nodes.
            int leftChildIdx = 2 * rootIdx;
            int rightChildIdx = 2 * rootIdx + 1;

            // find it's correct position, with comparing root node to its child nodes.

            // as we're inplementing MIN Heap,
            // value of root node is always <= it's child node.

            // comparing with left child.
            if (leftChildIdx < arr.size() && arr[rootIdx] > arr[leftChildIdx])
            {
                // if child nodes has smaller value then swap it.
                swap(arr[rootIdx], arr[leftChildIdx]);
                rootIdx = leftChildIdx;
            }

            // comparing with right child.
            else if (rightChildIdx < arr.size() && arr[rootIdx] > arr[rightChildIdx])
            {
                // if child nodes has smaller value then swap it.
                swap(arr[rootIdx], arr[rightChildIdx]);
                rootIdx = rightChildIdx;
            }

            else
            {
                // if root node has value <= from its child nodes then return.
                return;
            }
        }
    }

    /* Method to print vector/heap elements. */
    void print()
    {
        for (int i = 1; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};