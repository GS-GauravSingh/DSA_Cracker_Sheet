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


#include <bits/stdc++.h>
#include "../Stack Implementations/Stack_Implementation_Using_Array.h"
using namespace std;

/* Function to insert each element in sorted order */
void sortedInsert(Stack<int>& s, int element){
    //Base Case
    if(s.isEmpty() || s.top() < element){
        s.push(element);
        return;
    }

    //Recursive case
    int poppedElement = s.top();
    s.pop();
    sortedInsert(s, element);

    //Backtracking step(while comming back from the base case).
    s.push(poppedElement);
}


/* Function to sort a Stack */
void SortStack(Stack<int>& s){
    //Base Case
    if(s.isEmpty()){
        return;
    }

    // Recursive Case
    int poppedElement = s.top();
    s.pop();
    // make a recursive call.
    SortStack(s);

    //Backtracking step(while comming back from the base case), insert each element is sorted order.
    sortedInsert(s, poppedElement);
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

int main(void){
    Stack<int> s;
    s.push(10);   
    s.push(1);   
    s.push(5);   
    s.push(2);   
    s.push(3);   
    s.push(8);   
    s.push(9); 

    cout<<"Before:- \n";
    print(s);  

    cout<<"After:- \n";
    SortStack(s);
    print(s);  
}