
/*
Overall,

Time Complexity :-  O(n)
Space Complexity :-  O(n)
*/


#include<bits/stdc++.h>
#include"../Stack Implementations/Stack_Implementation_Using_Linked_List.h"
using namespace std;

/* Recursive Function to Find middle element of the Stack.
   TC :- O(n) , SC:- O(n), n/2 recursive stack space. 
*/
int Find_Middle_Element(Stack<int> &s, int i, int mid){
    // Base Case
    if(i == mid){
        // when i == mid, means we are at middle element.
        // return the middle element.
        return s.top();
    }

    // Recursive Case
    int poppedElement = s.top();
    s.pop();
    // make a recursive call.
    int middleElement = Find_Middle_Element(s, i+1, mid);

    // Backtracking Step(while comming back from the base case).
    // push the popped element into stack.
    s.push(poppedElement);

    // return the middle element
    return middleElement;
}

/* Recursive Function to delete middle element from the Stack.
   TC :- O(n) , SC:- O(n), n/2 recursive stack space.
*/
void delete_Middle_Element(Stack<int> &s, int i, int mid){
    // Base Case
    if(i == mid){
        // when i == mid, means we are at middle element.
        // So, pop the mid element and return from there.
        s.pop();
        return;
    }

    // Recursive Case
    int poppedElement = s.top();
    s.pop();
    // make a recursive call.
    delete_Middle_Element(s, i+1, mid);

    // Backtracking Step(while comming back from the base case).
    // push the popped element into stack.
    s.push(poppedElement);
}


/* Function to print stack:- TC :- O(n) , SC:- O(1)*/
void print(Stack<int> s){
    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
    
}

int main(void){
    Stack<int> s;

    // odd length
    // mid element = 9.
    // s.push(4);
    // s.push(2);
    // s.push(9);
    // s.push(5);
    // s.push(3);


    // // even length
    // // mid element = 6.
    s.push(8);
    s.push(7);
    s.push(6);
    s.push(4);

    int mid = s.size()/2;
    int i = 0;
    
    cout<<"Before Deletion:-\n";
    print(s);
    cout<<"Middle Element is => "<<Find_Middle_Element(s, i, mid)<<endl;
    
    cout<<"Deleting Middle Element is "<<endl;
    delete_Middle_Element(s, i, mid);

    cout<<"After Deletion:-\n";
    print(s);

    mid--; // one element is deleted from stack, that's why mid is decreased by one.
    cout<<"Middle Element is => "<<Find_Middle_Element(s, i, mid)<<endl;



}