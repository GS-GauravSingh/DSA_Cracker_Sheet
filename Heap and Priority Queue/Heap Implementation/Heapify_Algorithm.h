#include <bits/stdc++.h>
using namespace std;

/*
Note :- leaf nodes in complete binary tree are from,

in 1-based indexing :- ( (n/2) + 1)th index to nth index.
in 0-based indexing :- ( (n-1/2) + 1)th index to n-1th index.

*/

/*
Question:- What is Heapify Algorithm ?
Answer:- After inserting an elements into heap, it may not statisfy the heap property. In that case we need to adjust the location of the heap to make it heap again. This process is called heapifying.

in simple words, kisi given value of heapify krne ka matlab ye hai ki usko uski sahi position pe place krna hai.

Approach:-

So, basically you have to process nodes from index 1 to n/2. kyuki ((n/2)+1) se leke nth index take jo nodes hai vo leaf nodes hai or leaf nodes apne me hi ek valid heap hai toh leaf node ko process krne ki need hi nhi hai.

so, start iterating from back(n/2) and check if the current node is creating valid heap or not.
condition for valid heap (means root node value >= child nodes in case of MAX Heap or means root node value <= child nodes in case of MIN Heap).
*/


/*
Time Complexity of heapify algorithm:- O(log(n))
Time Complexity of Building Heap:- O(n)

Overall Time Complexity of heapify algorithm:- O(n log(n))

*/

class Heapify
{
public:
    /* Heapify Algotiyhm for MAX Heap (1-based indexing). */

    // size :- size of vector/array.
    // i :- it is the index of element which we have to place to its correct position.
    void maxHeapify(vector<int> &arr, int size, int i)
    {
        int rootIdx = i;              // we have to place this element to it's correct position.
        int leftChilIdx = 2 * i;      // left child index.
        int rightChilIdx = 2 * i + 1; // right child index.

        // compare, in case of MAX HEAP, root node value is always >= child nodes value.
        if (leftChilIdx <= size && arr[rootIdx] < arr[leftChilIdx])
        {
            rootIdx = leftChilIdx;
        }

        if (rightChilIdx <= size && arr[rootIdx] < arr[rightChilIdx])
        {
            rootIdx = rightChilIdx;
        }

        if (rootIdx != i)
        {
            // it means we got the right index for root.
            swap(arr[rootIdx], arr[i]);

            // make a recursive call for rest of the cases.
            maxHeapify(arr, size, rootIdx);
        }
    }


    /* Heapify Algotiyhm for MIN Heap (1-based indexing). */

    // size :- size of vector/array.
    // i :- it is the index of element which we have to place to its correct position.
    void minHeapify(vector<int> &arr, int size, int i)
    {
        int rootIdx = i;              // we have to place this element to it's correct position.
        int leftChilIdx = 2 * i;      // left child index.
        int rightChilIdx = 2 * i + 1; // right child index.

        // compare, in case of MIN HEAP, root node value is always <= child nodes value.
        if (leftChilIdx <= size && arr[rootIdx] > arr[leftChilIdx])
        {
            rootIdx = leftChilIdx;
        }

        if (rightChilIdx <= size && arr[rootIdx] > arr[rightChilIdx])
        {
            rootIdx = rightChilIdx;
        }

        if (rootIdx != i)
        {
            // it means we got the right index for root.
            swap(arr[rootIdx], arr[i]);

            // make a recursive call for rest of the cases.
            minHeapify(arr, size, rootIdx);
        }
    }

    /* Method to print vector/heap elements. */
    void print(vector<int> arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};