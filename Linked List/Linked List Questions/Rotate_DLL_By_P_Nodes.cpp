//  Time complexity:- O(n)
//  Space complexity:- O(1)


class Solution {
private:

//-------------- Function to get Tail of Linked List ----------------
    Node* getTail(Node* head){
        //Base Case
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        Node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        return temp;
    }
//--------------------------------------------------------------------

public:
    Node *rotateDLL(Node *head,int p)
    {
        //Step 1: find tail Node of Doubly Linked List
        Node* tail = getTail(head);
        
        //Step 2: find the tail node of List we have to reverse
        //ex:- 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 , P = 2
        // LL tail node = 6, rotate list tail node = 2.
        
        Node* rotateTail = head;
        int move = p-1;
        while(move--){
            rotateTail = rotateTail -> next;
        }
        // after this loop rotateTail will point to tail of list which i have to rotate
        // in above example, rotateTail will point to node with data = 2.
        
        //Step 3: we have to connect this rotate list to the tail of our original list.
        // making connections.
        // setting up our new head, seperate both list.
        Node* newHead = rotateTail -> next;
        rotateTail -> next = NULL;
        newHead -> prev = NULL;
        
        // joining rotate list to tail of our original list.
        tail -> next = head;
        head -> prev = tail;
        
        // return head or our rotated list
        return newHead;
        
    }
};