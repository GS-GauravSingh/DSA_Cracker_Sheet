#include <bits/stdc++.h>
using namespace std;

/* Heap Class, Implementing MAX HEAP, 1-based Indexing.

Note:-
# in 1-based indexing,
Parent Node is present at:- i / 2;
Left Child is present at:-  2 * i;
Right Child is present at:- 2 * i + 1;

# in 0-based indexing,
Parent Node is present at:- i-1 / 2;
Left Child is present at:-  2 * i + 1;
Right Child is present at:- 2 * i + 2;


Time Complexity:-

Insertion:- O(log(n))
Deletion:- O(log(n))
*/
class MAX_Heap
{
private:
    vector<int> arr;

public:
    // Constructor.
    MAX_Heap(int default_size = 10)
    {
        arr.reserve(default_size);
        arr.push_back(-1); // block the 0th index we are not gonna use that, we perform operations from index 1.

        cout<<"This is MAX Heap Implementation.\n";
    }

    // Methods,
    /*
    So, basically we visualize Heap as tree but we store its elements in the memory using arrays.

    Suppose there is a node in a vector at some ith location(index).

    if we are starting from index 1,
    Node = ith index.
    Parent of a Node:- its parent node is present at (i/2)th location(index).
    Left Child:- 2 * i index.
    Right Child:- 2 * i + 1 index.

    if we are starting from index 0,
    Node = ith index.
    Parent of a Node:- its parent node is present at (i-1/2)th location(index).
    Left Child:- 2 * i + 1 index.
    Right Child:- 2 * i + 2 index.


    Example MAX HEAP:-
                                            60
                                        /       \
                                    50         40
                                    /    \
                                30      20

    index:-          0  1  2  3  4  5
    array/vector = {-1,60,50,40,30,20};

    For node present at 1 index i.e., 60.
    node = 60 (i = 1)

    left child of 60 = 2 * i,
    = 2 * 1 = 2 at index 2 in vector 50 is present and the left child of 60 is 50.

    right child of 60 = 2 * i + 1,
    = 2 * 1 + 1 = 2 at index 2 in vector 40 is present and the right child of 60 is 40.


    For node present at 2 index i.e., 50.
    node = 50 (i = 2)

    left child of 50 = 2 * i,
    = 2 * 2 = 4 at index 4 in vector 30 is present and the left child of 50 is 30.

    right child of 50 = 2 * i + 1,
    = 2 * 2 + 1 = 5 at index 5 in vector 20 is present and the right child of 50 is 20.

    parent node of 50 = i/2 index,
    = 2/2 = 1 at index 1 in vector 60 is present and the parent node of 50 is 60.


    Let's perform Insertion in above example:-
    Example MAX HEAP:-
                                            60
                                        /       \
                                    50         40
                                    /    \
                                30      20

    index:-          0  1  2  3  4  5
    array/vector = {-1,60,50,40,30,20};

    we have to insert, let's say 55 in our MAX Heap(above example).

    Step 1:- insert that value (55) at the end of our vector/array.

    after inserting 55 in vector.
    index:-          0  1  2  3  4  5  6
    array/vector = {-1,60,50,40,30,20, 55};

    visualize tree:-
                                            60
                                        /       \
                                    50         40
                                    /    \     /
                                30      20  55

    Step 2:- take the inserted value (55) to its right position.
    to place 55 to its correct position, compare with its parent node (acc. to MIN and MAX Heap.) and swap the value.


    index:-          0  1  2  3  4  5  6
    array/vector = {-1,60,50,40,30,20, 55};
    visualize tree:-
                                            60
                                        /       \
                                    50         40
                                    /    \     /
                                30      20  55

    parent node of 55 :- i/2;  (55 is present at index 6 in our vector, so i = 6).
    parent node of 55 = i/2 = 6/2 = 3 (at index 3, parent node of 55 is present).
    parent of 55 is 40. So, acc. to MAX Heap root node is always >= it child nodes.
    swap(55,40);
    index:-          0  1  2  3  4  5  6
    array/vector = {-1,60,50,55,30,20, 40};
    visualize tree:-
                                            60
                                        /       \
                                    50         55
                                    /    \     /
                                30      20  40

    see, 55 is place at it's correct position.

    Node:- you have to do this step 2 until inserted value is place at it's correct position.


    */

    /* Method to push element into Heap. Time Complexity of Insertion:- O(log(n)) */
    void push(int element)
    {
        // step 1:- simply insert data at the end of our vector/array.
        arr.push_back(element);

        // step 2:- place inserted value to its correct position in vector.
        int insertedValueIdx = arr.size() - 1;

        while (insertedValueIdx > 1)
        {
            int parentNodeIdx = insertedValueIdx / 2; // in 1-based indexing, parent node of value inserted at ith index is present at index (i/2).

            // as we're inplementing MAX Heap,
            // value of root node is always >= it's child node.
            if (arr[parentNodeIdx] < arr[insertedValueIdx])
            {
                // if parent node value is less than it's child node then swap it.
                swap(arr[parentNodeIdx], arr[insertedValueIdx]);
                insertedValueIdx = parentNodeIdx;
            }
            else{
                return;
            }
        }
    }

    /*
    Let's perform Deletion:- always perfrom deletion from root node.
    Example:-
                                            60
                                        /       \
                                        50         40
                                    /    \
                                    30      20

    index:-          0  1  2  3  4  5
    array/vector = {-1,60,50,40,30,20};

    let's delete 60.

    Step 1:- replace or swap or put the value of last node with the node which you have to delete.

    arr[0] = arr[n-1];
    arr[0] = 20;
                                                20
                                            /       \
                                        50         40
                                        /    \
                                    30      20

    index:-          0  1  2  3  4  5
    array/vector = {-1,20,50,40,30,20};

    Step 2:- remove last node.
                                                20
                                            /       \
                                        50         40
                                        /
                                    30

    index:-          0  1  2  3  4
    array/vector = {-1,20,50,40,30};

    Step 3:- place root node to its correct position.
                                                50
                                            /       \
                                        30         40
                                        /
                                    20

    index:-          0  1  2  3  4
    array/vector = {-1,50,30,40,20};

    */

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

            // as we're inplementing MAX Heap,
            // value of root node is always >= it's child node.

            // comparing with left child.
            if (leftChildIdx < arr.size() && arr[rootIdx] < arr[leftChildIdx])
            {
                // if child nodes has larger value then swap it.
                swap(arr[rootIdx], arr[leftChildIdx]);
                rootIdx = leftChildIdx;
            }

            // comparing with right child.
            else if (rightChildIdx < arr.size() && arr[rootIdx] < arr[rightChildIdx])
            {
                // if child nodes has larger value then swap it.
                swap(arr[rootIdx], arr[rightChildIdx]);
                rootIdx = rightChildIdx;
            }

            else
            {
                // if root node has greater value (>=) than its child nodes then return.
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
