// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

// Reverse Stack using Recursion.
// To reverse a stack, you must know how to insert element at the bottom of the stack. 

#include <bits/stdc++.h>
#include "../Stack Implementations/Stack_Implementation_Using_Array.h"
using namespace std;

/* Insert At Bottom Function */
void insertAtBottom(Stack<int> &s, int data)
{
    // Base Case
    if (s.isEmpty())
    {
        // if stack is empty, insert data and return from there.
        s.push(data);
        return;
    }

    // Recursive Case
    int poppedElement = s.top();
    s.pop();

    // make a recursive call
    insertAtBottom(s, data);

    // Backtracking step (means while comming back from the base case).
    // we need to insert popped element.
    s.push(poppedElement);
}

/* Recursive Function to reverse Stack. */
void reverseStack(Stack<int> &stack)
{
    // Base Case
    if (stack.isEmpty())
    {
        return;
    }

    // Recursive Case
    // first we go to base case. So, store the top element somewhere
    // and the pop the top element and make a recursive call.
    int poppedElement = stack.top();
    stack.pop();
    // make a recursive call
    reverseStack(stack);

    // Backtracking step (means while comming back from the base case).
    // insert each popped element at bottom of the stack.
    insertAtBottom(stack, poppedElement);
}

/* Function to print Stack */
void print(Stack<int> s)
{
    while (!s.isEmpty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}
int main(void)
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<"Before Reverse:- \n";
    print(s);

    cout<<"After Reverse:- \n";
    reverseStack(s);
    print(s);
}