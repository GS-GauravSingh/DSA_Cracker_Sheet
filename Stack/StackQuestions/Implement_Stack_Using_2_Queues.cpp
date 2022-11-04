//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin >> Q;
        while (Q--)
        {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1)
            {
                int a;
                cin >> a;
                qs->push(a);
            }
            else if (QueryType == 2)
            {
                cout << qs->pop() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends

/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

// Function to push an element into stack using two queues.

/*
Steps for push operation:-
1. insert x into q2.
2. extract all elements from q1 and paste it into q2.
3. swap(q1,q2);

Example:-
---------------- push(3) ----------------;
step 1. insert x into q2.
queue 1:-
queue 2:- 3


step 2. extract all elements from q1 and paste it into q2.
queue 1:-
queue 2:- 3


step 3. swap(q1,q2);
queue 1:- 3
queue 2:-

---------------- push(4) ----------------;
step 1. insert x into q2.
queue 1:- 3
queue 2:- 4

step 2. extract all elements from q1 and paste it into q2.
queue 1:-
queue 2:- 4, 3


step 3. swap(q1,q2);
queue 1:- 4, 3
queue 2:-

---------------- push(2) ----------------;
step 1. insert x into q2.
queue 1:- 4, 3
queue 2:- 2

step 2. extract all elements from q1 and paste it into q2.
queue 1:- 4, 3
queue 2:-  2, 4, 3


step 3. swap(q1,q2);
queue 1:- 2, 4, 3
queue 2:-

---------------- push(1) ----------------;
step 1. insert x into q2.
queue 1:- 2,4, 3
queue 2:- 1

step 2. extract all elements from q1 and paste it into q2.
queue 1:- 2, 4, 3
queue 2:- 1, 2, 4, 3


step 3. swap(q1,q2);
queue 1:- 1, 2, 4, 3
queue 2:-


top() = 1;

for pop operation:- remove the top element from q1.

Time Complexity:- O(n)
Space Complexity:- O(n)

*/
void QueueStack ::push(int x)
{
    // step 1: push x in q2
    q2.push(x);

    // step 2:- extract all elements from q1 and paste it into q2.
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    // step 3. swap(q1,q2);
    swap(q1, q2);
}

// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    // for pop operation:- remove the top element from q1.
    if (q1.empty())
    {
        return -1;
    }

    int ans = q1.front();
    q1.pop();
    return ans;
}
