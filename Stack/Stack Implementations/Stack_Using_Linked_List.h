// Since we are using Linked List, we can push as much elements in our Linked List without any issue related to size.
// Our top element in case of LL is head.
// We perform insertion and deletion from head we don't need tail pointer in this case.

#include <iostream>
using namespace std;

template <typename T>
class Stack;



//------------------- Node structure for stack ---------------------
template <typename T>
class Node
{
private:
// Data members.
    T data;
    Node<T>* next;
public:
// Constructor.
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }

    friend class Stack<T>;

};


template <typename T>
class Stack
{
private:
    Node<T>* head;
public:
// Constructor.
    Stack(){
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
            // make newNode your newNode head.
            newNode -> next = head;
            head = newNode;
        }
    }

    // method to pop element from stack.
    void pop(){
        if(head != NULL){
            Node<T>* nodeToDelete = head;
            head = head -> next;
            delete nodeToDelete;
        }
        else{
            cout<<"Stack Underflow.\n";
        }
    }

    // method to get top element of the stack.
    T peek(){
        if(isEmpty()){
            cout<<"Stack is empty, please insert some elements.\n";
        }
        else{
            return head->data;
        }
    }

    // method to check if stack is empty or not.
    bool isEmpty(){
        if(head == NULL)return true;
        else{
            return false;
        }
    }

    // additional method to print Linked List
    void print(){
        if(isEmpty()){
            cout<<"Stack is empty.\n";
        }
        else{
            Node<T>* temp = head;
            while(temp != NULL){
                cout<< temp -> data << "\n";
                temp = temp -> next;
            }
            cout<<"\n";
        }
    }


};