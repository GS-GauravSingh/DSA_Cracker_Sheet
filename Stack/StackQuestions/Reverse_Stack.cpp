// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

// Reverse Stack using Recursion.
// To reverse a stack, you must know how to insert element at the bottom of the stack. 

#include<bits/stdc++.h>
// #include"../Stack Implementations/Stack_Using_Vector.h" // stack implementation file.
#include"Insert_Element_At_Bottom_Of_the_Stack.cpp" // because we have written insert at bottom funvtion in this file.
using namespace std;


void reverseStack(Stack<int> &s){
    // Base Case
    if(s.isEmpty()){
        // if stack is empty, simply return from there.
        return;
    }

    // Recursive Case

    // first we go to base case. So, store the top element somewhere
    // and the pop the top element and make a recursive call.

    int poppedElement = s.peek();
    s.pop();
    reverseStack(s);

    // Backtracking step
    // while comming back from the base case, 
    // insert each popped element at bottom of the stack.
    insertAtBottom(s,poppedElement);
    
}


int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout<<"Before Reverse.\n";
    s.print();
    cout<<"After Reverse.\n";
    reverseStack(s);
    s.print();
}