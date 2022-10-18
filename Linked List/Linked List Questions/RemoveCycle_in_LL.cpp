// Time complexity:- O(n) 
// Space Complexity:- O(1)


class Solution
{
    private:
    
    bool detectLoop(Node* &head)
    {
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast){
                //contains loop
                return true;
            }
        }
        
        return false;
    }
    
    Node* start_Node_Of_Cycle(Node* head){
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast!=NULL and fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow ==fast){
                break;
            }
        }
        // when slow == fast, initialize slow = head,
        // and move both pointer one node at a  time.
        slow = head;
        
        // and when slow == fast, that node is your starting node of cycle;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
    
    void remove(Node* head){
        // To remove a loop we heve to find the starting node of loop.
        if(head == NULL){
           return;
        }
        
        Node* startOfLoop = start_Node_Of_Cycle(head);
        Node* temp = startOfLoop;
        
        while(temp->next != startOfLoop){
            temp = temp->next;
        }
        
        temp->next = NULL;
    }
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(detectLoop(head) == true){
            // Linked List contains loop and 
            // we have to remove it.
            remove(head);
            
        }
        else{
            // LL does not have any loop.
            return;
        }
        
    }
};
