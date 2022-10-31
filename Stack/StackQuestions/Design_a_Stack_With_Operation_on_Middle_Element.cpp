#include <bits/stdc++.h>
using namespace std;

/*

Design a stack which will support the following operations in O(1) time complexity?
1) push() which adds an element to the top of stack.
2) pop() which removes an element from top of stack.
3) findMiddle() which will return middle element of the stack.

Approach:- To implement this, we are going to use linked list, because in case of array we cannot perform deletion in O(1) time complexity.  Also, we may need to move the middle pointer up when we push an element and move down when we pop(). In a singly linked list, moving the middle pointer in both directions is not possible.

The idea is to use a Doubly Linked List (DLL). We can delete the middle element in O(1) time by maintaining mid pointer. We can move the mid pointer in both directions using previous and next pointers.


If there are even elements in stack, findMiddle() returns the second middle element.
For example, if stack contains {1, 2, 3, 4}, then findMiddle() would return 3.
*/

// forward declaration of class Stack.
template <typename T>
class Stack;

// Node for doubly linked list.
template <typename T>
class Node
{
private:
    T data;
    Node<T> *next;
    Node<T> *prev;

public:
    // constructor for Node.
    Node(T data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }

    friend class Stack<T>;
};

template <typename T>
class Stack
{
private:
    Node<T> *head;
    Node<T> *mid;

    // count of elements in  DLL.
    int size;

public:
    // constructor.
    Stack()
    {
        head = mid = NULL;
        size = 0;
    }

    /* Function to push an element to the stack */
    void push(int data)
    {
        /*

        push():-
        odd number of nodes -> no operation.
        even number of nodes -> move mid one node previous (mid -> prev).

        */

        Node<T> *newNode = new Node<T>(data);
        if (head == NULL)
        {
            // empty list, hence insert 1st node.
            head = mid = newNode;
            size++;
        }
        else
        {
            // make connections
            newNode->next = head;
            head->prev = newNode;

            // make newNode as your new head
            head = newNode;

            // increment the size
            size++;

            if (size % 2 == 0)
            {
                mid = mid->prev;
            }
        }
    }

    /* Function to pop an element to the stack */
    T pop()
    {
        /*

        pop():-
        odd number of nodes -> move mid one node ahead (mid -> next).
        even number of nodes -> no operation.

        */
        T poppedElement = head->data;
        ;
        if (size == 0)
        {
            cout << "Stack Underflow.\n";
        }
        else if (size == 1)
        {
            head = mid = NULL;
            size = 0;
        }

        else
        {

            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            // decrement the size.
            size--;

            // update mid pointer.
            if (size & 1)
            {
                mid = mid->next;
            }
        }

        return poppedElement;
    }

    /* Function to get the middle element */
    T getMiddle()
    {
        if (size == 0)
        {
            cout << "From getMiddle(), Stack is Empty!!.\n";
            return -1;
        }
        return mid->data;
    }

    /* Function to get the top element */
    T top()
    {
        if (head == NULL)
        {
            cout << "From top(), Stack is Empty!!.\n";
            return -1;
        }
        return head->data;
    }

    /* Function to check for empty stack */
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
};

void print(Stack<int> s)
{
    if (s.isEmpty())
    {
        cout << "From print(), Stack is Empty!!.\n";
        return;
    }
    while (!s.isEmpty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Middle element is => " << s.getMiddle() << endl;
    print(s);


    cout << "Popped element = " << s.pop() << endl;
    cout << "Middle element is => " << s.getMiddle() << endl;
    print(s);

    cout<<"Popped element = "<<s.pop()<<endl;
    cout << "Middle element is => " << s.getMiddle() << endl;
    print(s);

    cout<<"Popped element = "<<s.pop()<<endl;
    print(s);
    cout << "Middle element is => " << s.getMiddle() << endl;
    
    cout<<"Popped element = "<<s.pop()<<endl;
    print(s);
    cout << "Middle element is => " << s.getMiddle() << endl;
}