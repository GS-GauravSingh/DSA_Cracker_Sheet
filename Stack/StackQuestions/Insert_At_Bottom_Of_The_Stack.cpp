// Time Complexity :-  O(n)
// Space Complexity :- O(n)

#include <bits/stdc++.h>
#include "../Stack Implementations/Stack_Implementation_Using_Vector.h"
using namespace std;

// Insert element at the bottom of the Stack.
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
    // to reach the base, we need to pop elements from stack and store popped element somewhere,
    // so that while comming back to base case, we need to insert that popped element.
    int poppedElement = s.top();
    s.pop();

    // make a recursive call
    insertAtBottom(s, data);

    // Backtracking step (means while comming back from the base case).
    // we need to insert popped element.
    s.push(poppedElement);
}

/* Function to print Stack */
void print(Stack<int> s){
    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
}

int main()
{

    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Before insertions.\n";
    print(s);
    cout << "After insertions.\n";
    insertAtBottom(s, 5);
    print(s);
}