// Ques:- Write a function that moves the last node to the front in a given Singly Linked List. 
// return the head of new linked list.

LinkedListNode<int>* moveToFront(LinkedListNode<int> *head) {
    //Base Cases
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    //Step 1: move temp to second last node.
    LinkedListNode<int>* temp = head;
    while(temp->next->next != NULL){
        temp = temp -> next;
    }
    // after this loop, temp will point to second last node.
    
    // Step 2: make connections
    LinkedListNode<int>* lastNode = temp->next;
    lastNode -> next = head; // pointing lastnode to head.
    head = lastNode; // make lastNode as our new head.
    temp->next = NULL; // connect second last node to NULL.
    
    // Step 3: return head
    return head;
}