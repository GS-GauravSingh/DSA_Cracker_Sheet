#include<iostream>
using namespace std;

// Circular LL :- last node is pointing to head node.

class Node{
private:
    int data;
    Node* next;
public:
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    // Deleting a node using destructor
    ~Node(){
        if(next!=NULL){
            delete next;
            
        }
        // cout<<"Deleting node with data "<<data<<endl;
        
    }

    friend class CircularLinkedList;
};

class CircularLinkedList{
private:
    Node* tail;
public:
    CircularLinkedList(){
        tail = NULL;
    }

    // Methods
    // print
    void print(){
        Node* head = tail->next;
        Node* temp = head;
        if(tail==NULL){
            cout<<"Linked List is empty\n";
            return;
        }
        do
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        } while (temp!=head);
    }

    // Insert at beginning
    void push_front(int data){
        if(tail==NULL){
            Node* newNode = new Node(data);
            tail = newNode;
            tail->next = newNode;
        }
        else{
            Node* newNode = new Node(data);
            Node* head = tail->next;
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    // Insert at end
    void push_back(int data){
        if(tail==NULL){
            Node* newNode = new Node(data);
            tail = newNode;
            tail->next = newNode;
        }
        else{
            Node* newNode = new Node(data);
            Node* head = tail->next;
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    // Insert at given position
    void insert(int data, int pos){
        // 1-based indexing
        if(pos==1){
            push_front(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* head = tail->next;
        Node* temp = head;
        for (int jump = 1; jump < pos-1; jump++)
        {
            temp = temp->next;
        }

        Node* n = temp->next;
        temp->next = newNode;
        newNode->next = n;
    }

    //Deletion entire linked list using destructor
    ~CircularLinkedList(){
        cout<<"\nDestructor Called. All data will be deleted.\n";
        Node* head = tail->next;
        if(head!=tail){
            tail->next = NULL;
            delete head;
            head = NULL;
        }
    }

    //Deleting Front node
    void pop_front(){
        if(tail==NULL){
            cout<<"Linked List is already Empty\n";
        }
        else if(tail->next==tail){
            tail = NULL;
            delete tail;
        }
        else{
            Node* head = tail->next;
            Node* temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    //Deleting Last node
    void pop_back(){
        if(tail==NULL){
            cout<<"Linked List is already Empty.\n";
        }
        else if(tail->next==tail){
            tail = NULL;
            delete tail;
        }
        else{
            Node* head = tail->next;
            Node* temp = head;
            //after this loop temp will reach to second last element
            while(temp->next->next!=head){
                temp = temp->next;
            }

            Node* last = tail;
            last->next = NULL;

            temp->next = head;
            tail = temp;

            delete last;
        }
    }

    // Deleting node at given position
    void deleteAtPos(int pos){
        // assume that pos <= len
        if(pos==1){
            // head node delete krna hai
            pop_front();
            return;

        }
        Node*  head = tail->next;
        Node*  temp = head;
        Node*  prev_temp = head;
        for (int i = 1; i <= pos-1; i++)
        {
            prev_temp = temp;
            temp = temp->next;
        }
        // jo node delete krna hai us pr point
        // krega temp.
        // jo node delete krna hai us se just phele
        // waale node pe point kreha prev_temp.
        prev_temp->next = temp->next;
        tail = prev_temp;
        temp->next = NULL;
        delete temp;
    }
};