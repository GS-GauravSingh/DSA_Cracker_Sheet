#include<iostream>
using namespace std;

template<typename T>
class Queue
{
private:
    T* arr; // to store elements of queue;
    int s; // to count number of element in the queue.
    int sizeOfArray; // capacity of array.
    int frontElement; // front element of queue.
    int rearElement; // rear element of queue
public:
    Queue(int size){
        this -> sizeOfArray = size; // setting up size of array.
        arr = new T[sizeOfArray];

        // initially array is empty.
        frontElement = rearElement = -1; 
        s = 0;
    }

    //Methods,
    // Method to Push 'X' in the front of the deque.
    void push_front(int data){
        // check for overflow condition
        if(isFull())
        {
            cout<<"Queue is full.\n";
        }
        else if(frontElement == -1)
        {
            //queue is empty, hence insert first element
            frontElement = rearElement = 0;
        }
        else if(frontElement == 0 && rearElement != sizeOfArray - 1)
        {
            // to maintaing cyclic nature.
            frontElement = sizeOfArray - 1;
        }
        else
        {
            // in normal case simply push.
            frontElement--;
        }

        arr[frontElement] = data;
        s++; // increment the size.
    }

    // Method to Push 'X' in the back/rear of the deque.
    void push_back(int data){
        
        //  check for overflow condition.
        if (isFull())
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

        s++; // increment the size.
    }

    //method to pop the front element.
    void pop_front(){
        //chock for underflow condition
        if(isEmpty()){
            cout<<"Queue is empty.\n";
        }
        else if(frontElement == rearElement)
        {   
            // single element is present.
            frontElement = rearElement = -1;
        }
        else if(frontElement == sizeOfArray - 1)
        {
            // while popping, if front reached the end of array.
            frontElement = 0;
        }
        else
        {
            // in normal case simply pop the element.
            frontElement++;
        }

        s--; // decrement the size.
    }

    //method to pop the rear/back element.
    void pop_back(){
        //chock for underflow condition
        if(isEmpty()){
            cout<<"Queue is empty.\n";
        }
        else if(frontElement == rearElement)
        {   
            // single element is present.
            frontElement = rearElement = -1;
        }
        else if(rearElement == 0)
        {
            // while popping, if front reached the end of array.
            rearElement = sizeOfArray - 1;
        }
        else
        {
            // in normal case simply pop the element.
            rearElement--;
        }

        s--; // decrement the size.
    }

    // method to check if queue is empty or not
    bool isEmpty(){
        if(frontElement == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    } 
    // method to check if queue is full or not
    bool isFull(){
        if ((frontElement == 0 && rearElement == sizeOfArray - 1) ||
        (frontElement != 0 && rearElement == (frontElement - 1)%(sizeOfArray - 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    } 

    // method to get the front element
    T getFront(){
        if(isEmpty()){
            cout<<"Queue is empty.\n";
            return -1;
        }
        else{
            return arr[frontElement];
        }
    }

    // method to get the rear element
    T getRear(){
        if(isEmpty()){
            cout<<"Queue is empty.\n";
            return -1;
        }
        else{
            return arr[rearElement];
        }
    }


    
};


