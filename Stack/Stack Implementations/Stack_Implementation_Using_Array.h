// Stack implementation using array or you can use vector, it's upto you.
// In vector:- you can simply insert element using push_back and pop element using pop back.

// in this we're going to use template. So, that you can create stack of any data type.

/*

All Methods having constant i.e., O(1) time complexity.

*/

#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    // pointer to array, size of array would be an user input.
    T *arr;

    // index to push elements in stack and to track if stack is empty or full.
    int topElement;

    // variable to store size of array.
    int sizeOfArray;

public:
    // parameterized constructor, take size of array.
    //  if user give size of array as input it uses that size otherwise it uses it's default initialization.
    Stack(int sizeOfArray = 1e5)
    {
        this->sizeOfArray = sizeOfArray; // setting up the size of array.
        arr = new T[sizeOfArray];        // T[sizeOfArray] => beacuse we are using template.
        topElement = -1;                 // -1 means array is empty.
    }

    // Stack Operations methods.

    // method to push element into stack.
    void push(int data)
    {
        // check for overflow condition
        if (topElement >= sizeOfArray)
        {
            // if stack is already full.
            cout << "Stack Overflow.\n";
        }
        else
        { // first increment topElement, because when array is empty, topElement will point to -1 and we cannot insert element at index -1.
            topElement++;
            arr[topElement] = data;
        }
    }

    // method to pop element form stack.
    void pop()
    {
        // check for underflow condition
        if (isEmpty())
        {
            // if stack is empty, you cannot pop element from empty stack.
            cout << "Stack Underflow.\n";
        }
        else
        {
            // if stack is not empty, you can pop the top element.
            topElement--;
        }
    }
    // method to get the top element of stack.
    T top()
    {
        // check for underflow condition
        // if isEmpty() return true, means stack is empty and we cannot see the top element from empty stack.
        if (isEmpty())
        {
            cout << "Stack is empty, please insert some element into stack to get the top element.\n";
            return -1;
        }
        else
        {
            // else return the top element.
            return arr[topElement];
        }
    }

    // method to get the size of stack.
    int size()
    {
        return top + 1;
    }

    // method to check is stack is empty or not.
    bool isEmpty()
    {
        // if topElement == -1 means array is empty else not.
        if (topElement == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
