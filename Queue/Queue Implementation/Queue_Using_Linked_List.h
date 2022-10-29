#include <iostream>
using namespace std;

// forward decleration of class Queue.
template <typename T>
class Queue;

// ------------------ Node structure for Queue ------------------
template <typename T>
class Node
{
private:
    // Because we're using templated class.
    T data;
    Node<T> *next;

public:
    // Constructor.
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }

    friend class Queue<T>;
};

// ------------------ Queue Class ------------------
template <typename T>
class Queue
{
private:
    // head is our front element of the queue and popping takes place at head.
    Node<T> *head;
    // insert elements at tail and it is used to track the rear element.
    Node<T> *tail;

    int s; // to count number of elements in the queue.
    // since we're using linked list there is no size limitation.
public:
    // Constructor
    Queue()
    {
        head = NULL;
        tail = NULL;

        s = 0;
    }

    // Methods,

    // method to push element into queue.
    void enqueue(T data)
    {
        // there is no need to check for overflow condition.
        // simply push elements.

        Node<T>* newNode = new Node<T>(data);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }

        s++;
    }

    // method to pop element from queue.
    void dequeue()
    {
        // case 1: check for underflow condition.
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
        }
        else
        {
            // if queue is not empty then,
            // case 2: simply pop element (head) from queue.
            cout << "Element [" << head -> data << "] successfully popped.\n";
            s--; // decrement the size.
            
            Node<T>* nodeToDelete = head;
            head = head -> next;
            delete nodeToDelete;
        }
    }

    // method to get the front Element of the queue.
    T front()
    {
        // case 1: check for underflow condition.
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        else
        {
            return head -> data;
        }
    }

    // method to get the rear Element of the queue.
    T rear()
    {
        // case 1: check for underflow condition.
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        else
        {
            return tail -> data;
        }
    }

    // method to get the size of the queue.
    int size()
    {
        return s;
    }


    // method to check if queue is empty or not.
    bool isEmpty()
    {
        if (head == NULL)
        {
            // means there is no element is the queue.
            return true;
        }
        else
        {
            return false;
        }
    }
};
