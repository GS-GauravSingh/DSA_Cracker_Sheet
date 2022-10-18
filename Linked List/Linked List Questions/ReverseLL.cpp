class Solution
{
    private:
    /* ------------------ Iterative Solution ---------------------------*/
    
    // Time Complexity: O(n), n is the number of nodes.
    // Space Complexity: O(1)
    
    
    struct Node* reverseIterative(struct Node* head){
        Node* prevNode = NULL;
        Node* currNode = head;
        Node* nextNode = NULL;
        
        while(currNode != NULL){
            // store the address of next node.
            nextNode = currNode -> next;
            
            // make a connection, that current Node points to previous Node.
            currNode -> next = prevNode;
            
            // move pointers
            prevNode = currNode;
            currNode = nextNode;
        }
        
        // at this point your [prevNode] is the head of reversed linked list.
        
        // head = prevNode;
        // return head;
        
        // or you can return prevNode also.
        return prevNode;
        
    }
    
    // /* ------------------ Iterative Solution ends here. ---------------------------*/
    
    
    // /* ------------------ Recursive Solution ---------------------------*/
    
    // // Time Complexity: O(n), n is the number of nodes.
    // // Space Complexity: O(n)
    
    // // Approach 1:
    
    void reverseRecursive_1(struct Node* &head, struct Node* prev, struct Node* curr, struct Node* nextNode){
        // Base Case
        if(curr == NULL){
            head = prev;
            return;
        }
        
        // Recursive Case
        nextNode = curr->next;
        curr->next = prev;
        
        reverseRecursive_1(head, curr, nextNode, nextNode);
  
    }
    
    
    // Approach 2:
    
    // Time Complexity: O(n), n is the number of nodes.
    // Space Complexity: O(n)
    
    struct Node* reverseRecursive_2(struct Node* &head){
        // Base Case
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        // Recursive Case
        struct Node* reverseHead = reverseRecursive_2(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return reverseHead;
    }
    

    /* ------------------ Recursive Solution ends here. ---------------------------*/
    
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // return head of reversed list
        // head = reverseIterative(head);
        // return head;
        
        
        Node* prevNode = NULL;
        Node* currNode = head;
        Node* nextNode = NULL;
        
        // reverseRecursive_1(head, prevNode, currNode, nextNode);
        // return head;
        
        // return reverseRecursive_2(head);
        
    }
    
};
