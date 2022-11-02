#include<bits/stdc++.h>
#include"../Queue Implementation/Queue_Using_Array.h"
#include"../../Stack/Stack Implementations/Stack_Implementation_Using_Vector.h"
using namespace std;

/* Function to print Queue */
void print(Queue<int> q){
    if(q.isEmpty()){
        cout<<"Queue is Empty.\n";
        return;
    }

    while(!q.isEmpty()){
        cout<<q.front()<<endl;
        q.dequeue();
    }cout<<endl;
}


/*

Approach 1:-  using Stack.

We know that if we insert any number of elements into stack, it came out in a reverse order.

Time Complexity:- O(n)
Space Complexity:- O(n)

*/
void reverseQueue_Using_Stack(Queue<int>& q){

    // using my own implementation of stack.
    Stack<int> s;

    //push all elements of queue into stack.
    while (!q.isEmpty())
    {
        s.push(q.front());
        q.dequeue();
    }

    //Now extract all elements from stack and put it into queue.
    while (!s.isEmpty())
    {
        q.enqueue(s.top());
        s.pop();
    }
    
    // Done.

}


/*

Approach 2:- using Recursion.


Time Complexity:- O(n)
Space Complexity:- O(n)

*/
    

void reverseQueue_Using_Recursion(Queue<int>& q){

    //Base Case
    if(q.isEmpty()){
        // when queue is empty return from there.
        return;
    }

    // first we go to the base case.
    int poppedElement = q.front();
    q.dequeue();
    // make a recursive call.
    reverseQueue_Using_Recursion(q);

    // Backtracking step(while comming back from the base case).
    // Insert the popped element into the queue.
    q.enqueue(poppedElement);

}

int main(void){
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout<<"Queue Before Reverse:- \n";
    print(q);

    cout<<"Queue After Reverse:- \n";
    reverseQueue_Using_Stack(q);
    reverseQueue_Using_Recursion(q);
    print(q);
}