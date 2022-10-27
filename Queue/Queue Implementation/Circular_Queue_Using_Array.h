#include <bits/stdc++.h>
class CircularQueue
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor
    CircularQueue(int n)
    {
        this->size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {
        // check for overflow condition.
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            //             cout<<"Queue is Full\n";
            return false;
        }
        else if (front == -1)
        {
            // means, we have to push first element in our queue.
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            // means rear reaches to end and there is no element at front (front != 0)
            // so, in that case, we need to start pushing elements from index 0.
            rear = 0;
        }
        else
        {
            // in this case simply increment rear.
            rear++;
        }

        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        // check for underflow condition.
        if (front == -1)
        {
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        {
            // means there is a single element.
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            // pop krte krte agar last tk pohuch gye toh, 0 se start kro.
            front = 0;
        }
        else
        {
            // normal case me simply front ko increment kro.
            front++;
        }

        return ans;
    }
};