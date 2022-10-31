#include <bits/stdc++.h>
using namespace std;

// All methods having O(1) time complexity and auxilary space.


// for stack 1:- perform operations from left to right.
// for stack 2:-  perform operations from right to left.

template <typename T>
class TwoStack
{
private:
    T *arr;          // array to store stack elements.
    int top1;        // top for stack 1.
    int top2;        // top for stack 2.
    int sizeOfArray; // capacity of array.

    int s1; // to count number of elements in stack 1.
    int s2; // to count number of elements in stack 2.

public:
    // parameterized constructor, takes size of array as input if given, otherwise size will initialize with its default value.
    TwoStack(int size = 1e5)
    {

        this->sizeOfArray = size; // setting up the size of array.
        arr = new T[sizeOfArray];

        // initially both stacks are empty.
        top1 = -1;
        top2 = sizeOfArray;

        // initially there is no element in stack.
        s1 = 0;
        s2 = 0;
    }

    // Methods,

    // Method to push an integer into the stack1.
    void push1(int data)
    {
        // check, if there is atleast one space is present
        if (top2 - top1 > 1)
        {
            // if the difference b/w top2 - top1 is > 1, it means empty spaces is present.

            top1++; // first increment top1, because initially top1 will point to -1.
            arr[top1] = data;
        }
        else
        {
            // if the difference b/w top2 - top1 is not > 1, there is no space present in array.
            cout << "Stack Overflow.\n";
        }

        // increment the count.
        s1++;
    }

    // Method to push an integer into the stack2.
    void push2(int data)
    {
        // check, if there is atleast one space is present
        if (top2 - top1 > 1)
        {
            // if the difference b/w top2 - top1 is > 1, it means empty spaces is present.

            top2--; // first decrement top2, because initially top2 will point to sizeOfArray.
            arr[top2] = data;
        }
        else
        {
            // if the difference b/w top2 - top1 is not > 1, there is no space present in array.
            cout << "Stack Overflow.\n";
        }

        // increment the count.
        s2++;
    }

    // Method to pop an integer form stack1.
    void pop1()
    {
        // check for underflow condition.
        if (IsEmpty1())
        {
            // if stack 1 is empty.
            cout << "Stack is Empty and You cannot pop element from empty stack.\n.";
        }
        else
        {
            // pop the top element.
            top1--;

            // decrement the count;
            s1--;
        }
    }

    // Method to pop an integer form stack2.
    void pop2()
    {
        // check for underflow condition.
        if (IsEmpty2())
        {
            // if stack 2 is empty.
            cout << "Stack is Empty and You cannot pop element from empty stack.\n.";
        }
        else
        {
            // pop the top element.
            top2++;

            // decrement the count;
            s2--;
        }
    }

    // Method to check if stack1 is empty or not.
    bool IsEmpty1()
    {
        if (top1 == -1)
        {
            // means stack 1 is empty.
            return true;
        }
        else
            return false;
    }

    // Method to check if stack2 is empty or not.
    bool IsEmpty2()
    {
        if (top2 == sizeOfArray)
        {
            // means stack 2 is empty.
            return true;
        }
        else
            return false;
    }

    // Method to return the top element of stack 1.
    T topElement_1(){
        if(IsEmpty1()){
            cout<<"Stack is empty.\n";
            return -1;
        }
        else{
            return arr[top1];
        }
    }

    // Method to return the top element of stack 2.
    T topElement_2(){
        if(IsEmpty2()){
            cout<<"Stack is empty.\n";
            return -1;
        }
        else{
            return arr[top2];
        }
    }

    // Method to return the size of stack 1.
    int size1(){
        if(IsEmpty1()){
            cout<<"Stack is Empty.\n";
            return 0;
        }
        return s1;
    }

    // Method to return the size of stack 2.
    int size2(){
        if(IsEmpty2()){
            cout<<"Stack is Empty.\n";
            return 0;
        }
        return s2;
    }
    
};

int main()
{
    TwoStack<char> ts;

    ts.push1('h');
    ts.push1('e');
    ts.push1('l');
    ts.push1('l');
    ts.push1('o');

    ts.push2('w');
    ts.push2('o');
    ts.push2('r');
    ts.push2('l');
    ts.push2('d');

    cout<<ts.topElement_1()<<endl;
    cout<<ts.topElement_2()<<endl;

    cout<<ts.size1()<<endl;
    cout<<ts.size2()<<endl;
}