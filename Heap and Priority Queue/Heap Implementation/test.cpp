#include <bits/stdc++.h>
#include "MAX_Heap_Implementation.h"
#include "MIN_Heap_Implementation.h"
#include "Heapify_Algorithm.h"
using namespace std;

int main()
{
    // Max Heap
    // MAX_Heap h;

    // h.push(20);
    // h.push(40);
    // h.push(10);
    // h.push(80);

    // h.print();

    // MIN Heap
    // MIN_Heap mh;
    // mh.push(80);
    // mh.push(10);
    // mh.push(40);
    // mh.push(20);

    // mh.print();


    // Heapify Algorithm.
    Heapify hi;
    vector<int> arr1 = {-1, 54, 53, 55, 52, 50};
    vector<int> arr2 = {-1, 54, 53, 55, 52, 50};

    // Building Heap (MAX Heap).
    // Building Heap having Time Complexity:- O(n)
    int size = arr1.size()-1;
    for (int i = size/2; i > 0; i--)
    {
        hi.maxHeapify(arr1,size,i);
    }

    hi.print(arr1);

    // Building Heap (MIN Heap).
    // Building Heap having Time Complexity:- O(n)
    size = arr2.size()-1;
    for (int i = size/2; i > 0; i--)
    {
        hi.minHeapify(arr2,size,i);
    }

    hi.print(arr2);
    
}