#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    T *arr;          // to store elements of queue.
    int sizeOfArray; // represents the capacity of array.
    int frontElement;       // represent the frontElement (the one element who comes first) element of queue.
    int rearElement;        // represent the rearElement (last) element of queue.

    int s; // to count the elements present in the array.
public:
    // Parameterized Constructor, takes size of array as input if given, if size is not given it will initialize with its default value.
    Queue(int sizeOfArray = 1e5)
    {
        // 1e5 means 10^5;
        this->sizeOfArray = sizeOfArray; // setting up the size of array.
        arr = new T[sizeOfArray];        // because we're using a templated class.
        frontElement = rearElement = 0;                // initially frontElement and rearElement is 0, because there is no element in the queue.

        s = 0; // initially size of array is 0.
    }

    // Methods,

    // method to push element into queue.
    void enqueue(T data)
    {
        // case 1: check for overflow condition.
        if (rearElement == sizeOfArray)
        {
            cout << "Queue is Full.\n";
        }
        else
        {
            // if there is a space in queue then,
            // case 2: simply insert element into queue.
            arr[rearElement] = data;
            rearElement++;
        }

        s++;
    }

    // method to pop element from queue.
    void dequeue()
    {
        // case 1: check for underflow condition.
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
        }
        else
        {
            // if queue is not empty then,
            // case 2: simply pop element from queue.
            cout<<"Element ["<<arr[frontElement]<<"] successfully popped.\n";
            frontElement++;
            s--; // decrement the size.
            
            // check, while popping if frontElement reache the end of the queue.
            //ex: arr = {a,b,c,d,r}; frontElement = a, rearElement = r;
            // while popping frontElement reaches to end, means frontElement == rearElement, in that case reinitialize frontElement and rearElement with 0.
            if(frontElement == rearElement){
                frontElement = rearElement = 0;
            }
        }
    }

    // method to get the front Element of the queue.
    T front()
    {
        // case 1: check for underflow condition.
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        else
        {
            return arr[frontElement];
        }
    }

    // method to get the rear Element of the queue.
    T rear()
    {
        // case 1: check for underflow condition.
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        else
        {
            return arr[rearElement];
        }
    }

    // method to get the size of the queue.
    int size()
    {
        return s;
    }

    // method to get the capacity of the queue.
    int capacity()
    {
        return sizeOfArray;
    }

    // method to check if queue is empty or not.
    bool isEmpty()
    {
        if (frontElement == rearElement)
        {
            // means there is no element is the queue.
            return true;
        }
        else
        {
            return false;
        }
    }
};
