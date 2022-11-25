/*
What is Heap Sort
Heap sort is a comparison-based sorting technique based on Binary Heap data structure. It is similar to the selection sort where we first find the minimum element and place the minimum element at the beginning. Repeat the same process for the remaining elements.

Note:-
1. Heap sort is an in-place algorithm.
2. Its typical implementation is not stable, but can be made stable (See this)
3. Typically 2-3 times slower than well-implemented QuickSort.  The reason for slowness is a lack of locality of reference.


Algorithm:-
1st.  swap(arr[1], arr[n]);  // choose arr[0] or arr[1] according to 0 or 1 based indexing and delete last element.
2nd. place root node to its correct position.
*/
#include <bits/stdc++.h>
#include "../Heap Implementation/Heapify_Algorithm.h"
using namespace std;

Heapify hi;

// Heap sort
void heapSort(vector<int> &arr)
{
    int size = arr.size() - 1;

    while (size > 1)
    {
        // step 1:- swap
        swap(arr[size], arr[1]);
        size--;

        // step 2:- place root node to its correct position.
        hi.maxHeapify(arr, size, 1);
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


int main()
{
    // heap sort
    // creating max heap.
    vector<int> arr = {-1, 54, 53, 55, 52, 50};
    int size = arr.size() - 1;
    for (int i = size / 2; i > 0; i--)
    {
        hi.maxHeapify(arr, size, i);
    }

    cout << "Before Heap Sort (MAX Heap):-\n";
    print(arr);


    heapSort(arr); // heap sort function call.

    cout << "After Heap Sort (MAX Heap):-\n";
    for (int i = 1; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
