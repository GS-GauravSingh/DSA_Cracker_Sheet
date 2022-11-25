#include <bits/stdc++.h>
using namespace std;
/* Heapify Algotiyhm for MAX Heap (0-based indexing). */

// size :- size of vector/array.
// i :- it is the index of element which we have to place to its correct position.
void maxHeapify(vector<int> &arr, int size, int i)
{
    int rootIdx = i;              // we have to place this element to it's correct position.
    int leftChilIdx = 2 * i + 1;      // left child index.
    int rightChilIdx = 2 * i + 2; // right child index.

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

// function to convert MIN heap to MAX heap.
void convert(vector<int> &arr){
    int size = arr.size()-1;
    for (int i = size/2; i >= 0; i--)
    {
        maxHeapify(arr,size,i);
    }
    
}


/* Function to print vector. */
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Given an array representation of min Heap, convert it to max Heap.
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    convert(arr);
    print(arr);
}