#include <iostream>
using namespace std;

// All methods having time complexity  O(1).

template <typename T>
class Queue
{
private:
    // So, we need,
    // 1. array to store elements
    // 2. size (represents size of queue).
    // 3. front (represents front element of queue).
    // 4. rear (where we push elements into queue).

    int size;  // size of array.
    T *arr;  // pointer to array.
    int front; // represent front element of queue.
    int rear;  // we push elememts into queue from rear.
    // initially rear and front both points to index 0, it means when front == rear, menas array is empty.
public:

    // Constructor
    // agar size input me mila toh theik hai, agar nhi mila to default size 10^5 hoga. 
    Queue(int size = 1e5)
    {
        this -> size = size;
        arr = new T[size];
        front = 0;
        rear = 0;
    }

    // push elements into queue.
    void enqueue(T data){
        //check if queue is full or not
        if(rear == size){
            cout<<"Queue is Full.\n";
        }
        else{
            //simply insert element into queue.
            arr[rear] = data;
            rear++;
        }
    }

    // pop elements from queue.
    void dequeue(){
        //check if queue is empty or not
        if(isEmpty()){
            cout<<"Queue is already empty,Please insert some elements to perform pop() operation.\n";

        }
        else{
            //store the popped element, then set popped element to -1. 
            // arr[front] = -1;
            front++;

            // if front == rear means array is empty.
            if(front == rear){
                rear = 0;
                front = 0;
            }
        }
    }

    // return front element
    T getFront(){
        //check if queue is empty or not
        if(isEmpty()){
            cout<<"Queue is already empty,Please insert some elements to get front element.\n";
            return -1;
        }
        else{
            return arr[front];
        }
    }

    // check for empty queue
    bool isEmpty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    // get the size of stck
    int getSize(){
        return rear;
    }

};
