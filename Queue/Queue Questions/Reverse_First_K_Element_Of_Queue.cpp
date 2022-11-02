#include<bits/stdc++.h>
using namespace std;

/* Function to print Queue */
void print(queue<int> q){
    if(q.empty()){
        cout<<"Queue is Empty.\n";
        return;
    }

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }cout<<endl;
}

/* Function to reverse first k elements of a queue.

Time complexity:- O(k) + O(k) + O(n-k), constraints gives 1<= k <= N.
                  O(n) + O(n) + O(n-n)

Time Compexity:- O(n)       
Space complexity:- O(k)

*/
queue<int> modifyQueue(queue<int> q, int k) {
    /* 
    Step 1: put first k elements into stack.
    Ex:- queue = {1,2,3,4,5};
    after insert k elements into stack,
    stack =>  3
              2
              1
    and queue becomes => {4,5};

    Step 2:- extract all elements from stack and put it into queue.
    before insertion queue => {4,5};
    after insertion queue => {4,5,3,2,1};

    Step 3:- extract rest n-k elements and push it into queue.
    before => {4,5,3,2,1};
    after  => {3,2,1,4,5};
    */

   // Step 1:- put first k elements into stack.
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    //Step 2:- extract all elements from stack and put it into queue.
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // Step 3:- extract rest n-k elements and push it into queue.
    int i = q.size() - k;
    while(i--){
        q.push(q.front());
        q.pop();
    }
    
    return q;
}

int main(void){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;
    cout<<"Before Reverse:-\n";
    print(q);
    cout<<"After Reverse:-\n";
    queue<int> ans = modifyQueue(q,k);
    print(ans);
}