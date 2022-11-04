#include <bits/stdc++.h>
using namespace std;

class Stack
{
    deque<int> dq;
public:

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        /*
        perform push and pop from front, or you can push and pop form back also.

        Example:- push(1)
        dq = 1;

        push(2);
        dq = 2, 1

        push(3);
        dq = 3, 2, 1

        push(4);
        dq = 4, 3, 2, 1

        pop();
        dq =  3, 2, 1

        pop();
        dq =  2, 1

        pop();
        dq =  1
        */

        dq.push_front(x);
        return true;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
        if (dq.empty())
        {
            return -1;
        }
        int ans = dq.front();
        dq.pop_front();
        return ans;
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        if (dq.empty())
        {
            return -1;
        }
        int ans = dq.front();
        return ans;
    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
        if (dq.empty())
        {
            return true;
        }
        return false;
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        dq.size();
    }
};

int main()
{
    
}