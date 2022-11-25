#include <bits/stdc++.h>
#include "../../Linked List/Linked Lists Implementations/SinglyLinkedList.h"
using namespace std;

/*
Approach:- Uisng MIN Heap.

Step 1:- Create MIN Heap.
Step 2:- saare k Linked List ke 1st element ko MIN Heap me insert krdo.
Note:- after step 1, in saare k Linked List ke 1st elements me se jo minimum element hoga vo heap.top() pe present hoga.
step 3:- create head and tail for answer Linked List.
Step 4:- while(heap is not empty){
    Step 5:- minimum element ko ans Linked List me store krlo or pop krodo heap me se.
    Step 6:- saare k Linked List ke next element ko heap me insert krdo.
}

Time Complexity:- O(n*k log(k))
Space Complexity:- O(k)

*/


// custom comparator class.

// class Compare
// {
// public:
//     bool operator()(Node<int> *a, Node<int> *b)
//     {
//         // compare on the basis of data.
//         return a->data > b->data;
//     }
// };

// Node<int> *mergeKLists(vector<Node<int> *> &listArray)
// {
//     // Step 1:- create MIN Heap.
//     priority_queue<Node<int> *, vector<Node<int> *>, Compare> minHeap;

//     // Step 2:- saare k Linked List ke 1st element ko MIN Heap me insert krdo.
//     int k = listArray.size();
//     if (k == 0)
//     {
//         return NULL;
//     }
//     for (int i = 0; i < k; i++)
//     {
//         if (listArray[i] != NULL)
//         {
//             minHeap.push(listArray[i]);
//         }
//     }

//     // Step 3;
//     Node<int> *head = NULL;
//     Node<int> *tail = NULL;

//     // step 4:-
//     while (minHeap.size() > 0)
//     {

//         // Step 5:- minimum element ko ans Linked List me store krlo or pop krodo heap me se.
//         Node<int> *top = minHeap.top();
//         minHeap.pop();

//         // Step 6:- saare k Linked List ke next element ko heap me insert krdo.
//         if (top->next != NULL)
//         {
//             minHeap.push(top->next);
//         }

//         // insert in Linked List.
//         if (head == NULL)
//         {
//             head = tail = top;
//         }
//         else
//         {
//             tail->next = top;
//             tail = top;
//         }
//     }

//     return head;
// }

int main()
{
}