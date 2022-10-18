// Time Complexity:- O(n)
// Space Complexity:- O(1)


//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    // Base Cases
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    Node* temp = head;
    while(temp != NULL && temp -> next != NULL){
        
        if(temp -> data == temp -> next -> data){
            
            // Duplicate elements
            Node* nodeTodelete = temp -> next;
            temp -> next = temp -> next -> next;
            nodeTodelete -> next = NULL;
            delete nodeTodelete;
            
        }
        else{
            // Unique elements
            // move pointer temp.
            temp = temp->next;
        }
        
    }
    return head;
 
}
