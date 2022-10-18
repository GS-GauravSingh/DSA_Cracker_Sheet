
// Time Complexity :-  O(n)
// Space Complexity :- O(n)


#include<bits/stdc++.h>
#include"../Stack Implementations/Stack_Using_Vector.h"
using namespace std;

// Insert element at the bottom of the Stack.
void insertAtBottom(Stack<int> &s, int data){
    // Base Case
    if(s.isEmpty()){
        // if stack is empty, insert data and return from there.
        s.push(data);
        return;
    }

    // Recursive Case
    // to reach the base, we need to pop elements from stack and store popped element somewhere,
    // so that when we came back to base case, we need to insert that popped element.
    int poppedElement = s.peek();
    s.pop();

    // make a recursive call
    insertAtBottom(s, data); 

    // Backtracking step (means while comming back from the base case).
    // we need to insert popped element.
    s.push(poppedElement);
}

/*

Commenting out main function because we use this file in our reverse stack file.

*/


// int main(){

//     Stack<int> s;

//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);

//     cout<<"Before insertions.\n";
//     s.print();
//     cout<<"After insertions.\n";
//     insertAtBottom(s, 5);
//     s.print();

// }