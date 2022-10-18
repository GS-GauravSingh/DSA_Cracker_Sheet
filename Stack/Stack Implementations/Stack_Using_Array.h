// Stack implementation using array or you can use vector, it's upto you.
//In vector:- you can simply insert element using push_back and pop element using pop back.

// in this we're going to use template. So, that you can create stack of any data type.

/*

All Methods having constant i.e., O(1) time complexity, except print having O(n) time complexity (because we are printing all elements) .

*/


#include <iostream>
using namespace std;


template <typename T>
class Stack
{
private:

    // index to push elements in stack and to track if stack is empty or full.
    int top;
    // pointer to array, size of array would be an user input.
    int* arr;
    //size of array
    int size;

public:
    //parameterized constructor, take size of array.
    Stack(int size){
        top = -1; // -1 means array is empty.
        this->size = size; // setting up the size of array.
        arr = new T[size]; // beacuse we are using template.
    }

    // Stack Operations methods.

    // method to push element into stack.
    void push(T data){
        //checking, if stack has space for element or not
        if(top < size){
            top++; // first increment top, because when array is empty, top will point to -1 and we cannot insert element at index -1.
            arr[top] = data;
        }
        else{
            // if stack is already full.
            cout<<"Stack Overflow\n";
        }
    }

    // method to pop element form stack.
    void pop(){
        // if top >= 0, means array contains some element to pop.
        if(top >= 0){
            top--;
        }
        else{
            // if top < 0,  means array is empty and we cannot pop element empty array.
            cout<<"Stack Underflow\n"; 
        }
    }

    // method to check is stack is empty or not.
    bool isEmpty(){
        // if top == -1 means array is empty else not.
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    // method to get the top element of stack.
    T peek(){
        // if isEmpty() return true, means stack is empty and we cannot see the top element from empty stack.
        if(isEmpty()){
            cout<<"Stack is empty.\n";
            return -1;
            
        }
        else{
            //else return element. 
            return arr[top];
        }
    }

    // method to get the size of stack.
    int currentSize(){
        return top+1;
    }

    // additional method to print stack element
    void print(){
        if(isEmpty()){
            cout<<"Insert some elements to print. Currently stack is empty\n.";
        }
        else{
            for (int i = top; i >= 0; i--)
            {
                cout<<arr[i]<<"\n";
            }cout<<"\n";
            
        }
    }
};
