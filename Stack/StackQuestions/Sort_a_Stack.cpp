/*
Ques:- Sort a stack using recursion.

Approach:- first we go to the base case and while comming back from the base case insert each element in the stack in sorted manner.

Example:- you have to sort the stack like this,

    Stack I/O                   Stack O/P
      3                            9
     -7                            5
      9                            3
     -2                           -2
      5                           -7

minimum element is at the bottom.
*/

/*
Time Complexity:- O(n^2)
Space Complexity:- O(n)
*/

#include<bits/stdc++.h>
#include"../Stack Implementations/Stack_Using_Vector.h"
using namespace std;

// Function that inserts elements into stack in sorted order using recursion.

// when we found the value smaller than the element we want to insert push it into stack.
void sortedInsert(Stack<int>& s, int element){
    // Base Case
    if(s.isEmpty() || s.peek() < element){
        s.push(element);
        return;
    }

    //Recursive case
    int poppedElement = s.peek();
    s.pop();
    sortedInsert(s, element);

    //Backtracking step(while comming back from the base case).
    s.push(poppedElement);

}

// sort stack recursive function
void sortStack(Stack<int>& s){
    //Base Case
    if(s.isEmpty()){
        return;
    }

    // Recursive Case
    int poppedElement = s.peek();
    s.pop();
    sortStack(s);

    //Backtracking step(while comming back from the base case), insert each element is sorted order.
    sortedInsert(s, poppedElement);
}

int main(){
    Stack<int> s;
    s.push(3);
    s.push(-7);
    s.push(9);
    s.push(-2);
    s.push(5);

    sortStack(s);
    s.print();
}