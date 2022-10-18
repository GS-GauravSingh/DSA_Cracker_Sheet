// Ques:- Implement two stack using single array.

// Approach:- for stack 1 insert elements from left to right and for stack 2 insert elemnts from right to left.

#include<iostream>
using namespace std;

class TwoStack
{
private:
    int* arr;
    int top1; // top for stack 1.
    int top2; // top for stack 2.
    int size; // size of array.

public:
    // Constructor .
    TwoStack(int s)
    {
        //setting up size and top.
        this -> size = s;
        top1 = -1; // for stack 1 we start inserting from left, -1 means stack 1 is empty.
        top2 = s; // for stack 2 we start inserting from right, if top2 == s means stack 2 is empty.
        arr = new int[size];
    }

    // Push elements in stack 1.
    void push1(int num)
    {
        // check if stack is empty or not
        // if top2 - top1 > 1 means there is a space element.
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = num;
        }
        else{
            cout<<"Stack Overflow\n.";
        }
    }

    // Push elements in stack 2.
    void push2(int num)
    {
        // check if stack is empty or not
        // if top2 - top1 > 1 means there is a space element.
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = num;
        }
        else{
            cout<<"Stack Overflow\n.";
        }
        
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            //top1 < 0, means stack is empty.
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            //top2 == size, means stack is empty.
            return -1;
        }
    }
};