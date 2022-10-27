#include <iostream>
using namespace std;

// All methods having time complexity  O(1).

template <typename T>
class Queue;


template <typename T>
class Node
{
private:
    T data;
    Node<T> *next;

public:
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }

    friend class Queue<T>;
};

template <typename T>
class Queue
{
private:
    // we insert elements from tail.
    Node<T> *head;
    Node<T> *tail;
    int size; // to get the size od Linked List.

public:
    // constructor
    Queue()
    {
        head = tail = NULL;
        size = 0;
    }

    // Methods
    // push elements into queue.
    void enqueue(T data)
    {
        // in case of linked List, there is no need to check for overflow conditions.
        // Simply push element.
        Node<T>* newNode = new Node<T>(data);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }

        size++;// counting the number of elements.     
    }

    // pop elements from queue.
    void dequeue()
    {   
        // chek for underflow condition.
        if(isEmpty()){
            cout<<"Queue is already empty, Please insert some elements to perform pop() operation.\n";
        }        
        else{
            // we need to delete head node.
            Node<T>* nodeToDelete = head;
            head = head -> next;
        }
    }

    // return front element
    T getFront()
    {
        if(isEmpty()){
            cout<<"Queue is already empty, Please insert some elements to get the front element.\n";
        }
        else{
            return head -> data;
        }
    }

    // check for empty queue
    bool isEmpty()
    {
        if(head == NULL){
            return true;
        }      
        else{
            return false;
        }  
    }

    // get the size of stck
    int getSize()
    {
        return size;
    }
};
