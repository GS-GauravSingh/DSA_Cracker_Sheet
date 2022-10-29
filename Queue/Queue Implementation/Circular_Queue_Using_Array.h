#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    T* arr; //to store element of queue.
    int sizeOfArray; // represents the capacity of array.
    int frontElement; // represents the frontElement element of queue.
    int rearElement; // represents the rearElement (last) element of queue.
    int s; // used to count the number of elements of queue.
public:
    // Constructor.
    Queue(int sizeOfArray = 1e5)
    {
        this -> sizeOfArray = sizeOfArray;// setting up the size of array.
        arr = new T[sizeOfArray];
        frontElement = rearElement = -1; // this will set to -1, because initially there is no element in the queue.

        s = 0; // initially there is no element in the queue.
    }

    // Methods,

    // method to push element into queue.
    void enqueue(T data)
    {
        // case 1: check for overflow condition.
        if ((frontElement == 0 && rearElement == sizeOfArray - 1) ||
        (rearElement == (frontElement - 1)%(sizeOfArray - 1)))
        {
            cout << "Queue is Full.\n";
        }
        else if(frontElement == -1)
        {
            //Queue is empty, hence insert the first element
            frontElement = rearElement = 0;
        }
        else if(rearElement == sizeOfArray - 1 && frontElement != 0)
        {
            // If rear reaches end of queue but the first element is empty.
            rearElement = 0;
        }
        else
        {
            // simply push the element
            rearElement++;
        }

        arr[rearElement] = data;

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
        else if(frontElement == rearElement)
        {
            // if the queue has only one element.
            frontElement = rearElement = -1;            
        }
        else if(frontElement == sizeOfArray - 1)
        {
            // while popping, if front reached the end of array.
            frontElement = 0;
        }
        else{
            // in normal case simply pop the element.
            frontElement++;
        }
        s--; //decrement the size.
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
        if (frontElement == -1)
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