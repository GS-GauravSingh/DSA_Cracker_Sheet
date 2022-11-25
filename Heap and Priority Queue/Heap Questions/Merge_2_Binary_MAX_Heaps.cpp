#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity:- O(n log(n))
Space Complexity:- O(n+m)
*/


// Heapify Max Heap
void maxHeapify(vector<int> &arr, int n, int i)
{
    int rootIdx = i;
    int leftChildIdx = 2 * i + 1;  // 0-based indexing.
    int rightChildIdx = 2 * i + 2; // 0-based indexing.

    // compare, in case of MAX HEAP, root node value is always >= child nodes value.
    if (leftChildIdx < n && arr[rootIdx] < arr[leftChildIdx])
    {
        rootIdx = leftChildIdx;
    }
    if (rightChildIdx < n && arr[rootIdx] < arr[rightChildIdx])
    {
        rootIdx = rightChildIdx;
    }

    if (rootIdx != i)
    {
        // it means we got the right index for root.
        swap(arr[rootIdx], arr[i]);

        // make a recursive call for rest of the cases.
        maxHeapify(arr, n, rootIdx);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // Base Case
    if (n == 0)
    {
        return b;
    }
    if (m == 0)
    {
        return a;
    }

    // Step 1:- merge both vectors into one, in any order.
    for (int i = 0; i < b.size(); i++)
    {
        a.push_back(b[i]);
    }

    // Step 2:- heapify (MAX Heapify) the mergerd vector.

    // creating MAX Heap.
    int size = a.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        maxHeapify(a, size, i);
    }

    return a;
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
    // Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    int n = a.size();
    int m = b.size();

    vector<int> merge = mergeHeaps(a, b, n, m);
    print(merge);
}