// Since we are using Linked List, we can push as much elements in our Linked List without any issue related to size.
// Our top element in case of LL is head.
// We perform insertion and deletion from head we don't need tail pointer in this case.

#include <iostream>
using namespace std;

// forward declaration of class Stack
template <typename T>
class Stack;

// ------------ Node structure ---------------------------
template <typename T>
class Node
{
private:
    // because we're using a templated class.
    T data;
    Node<T> *next;

public:
    // constructor
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }

    friend class Stack<T>;
};

// ---------------------- Stack Class --------------------
template <typename T>
class Stack
{
private:
    // all we need is a head pointer.
    Node<T> *head;
    int s = 0 ; // to store the size of stack.

public:
    // constructor.
    Stack()
    {
        head = NULL;
    }

    // Methods.

    // method to push element into stack.
    void push(T data){
        Node<T>* newNode = new Node<T>(data);
        if(head == NULL){
            head = newNode;
        }
        else{
            // all insertions takes place at head.
            // make newNode your newNode head.
            newNode -> next = head;
            head = newNode;
        }

        s++;
    }

    // method to pop element from stack.
    void pop(){
        // check for underflow condition
        if(head != NULL){
            Node<T>* nodeToDelete = head;
            head = head -> next;
        }
        else{
            cout<<"Stack Underflow.\n";
        }
    }

    // method to check if stack is empty or not.
    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    // method to get top element of the stack.
    T top(){
        if(isEmpty()){
            cout<<"Stack is empty, please insert some elements to get the top element.\n";
        }
        else{
            return head->data;
        }
    }

    // method to get size of stack.
    int size(){
        return s;
    }
};