#include<bits/stdc++.h>
#include"../Stack Implementations/Stack_Using_Vector.h"
using namespace std;


/*

Time Complexity:- O(n), because we are traversing n/2 nodes. 
Space COmplexity:- O(n), n/2 stack space.

*/
void deleteMiddleElement(Stack<int> &s, int mid, int i){
    //Base Case
    if(i == mid){
        // when i reaches to mid, pop the middle element.
        // and return from there.
        s.pop();
        return;
    }

    // Recursive case
    int poppedElement = s.peek();
    s.pop();
    deleteMiddleElement(s, mid, i+1);

    //Backtracking step(while comming back from base case).
    s.push(poppedElement);
}


int main(){
    Stack<int> s;

// odd length
    // s.push(1);    
    // s.push(2);    
    // s.push(3);    
    // s.push(4);    
    // s.push(5);
    // s.push(6);
    // s.push(7);

    // //when length is odd middle element would be (size/2) and i start from 0.
    // int mid = (s.size()/2);
    // int i = 0;
    // deleteMiddleElement(s, mid, i);
    // s.print();    
      

// even length
    s.push(5);    
    s.push(6);    
    s.push(7);    
    s.push(8);    
    // s.push(5);    
    // s.push(6); 

    //when length is even middle element would be (size/2) and i start from 0.
    int mid = (s.size()/2);
    int i = 0;
    deleteMiddleElement(s, mid, i);
    s.print();    
}