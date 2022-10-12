class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Base Case, if NULL occurs, it means no cycle in Linked List.
        if(head==NULL || head->next == NULL) return NULL;
        
      // Initializing pointers.
        ListNode *slow = head, *fast = head;
        
        while(fast != NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
              // if both meets break the loop.
                break;
            }
        }
        // just a check if slow != fast, means no cycle, return NULL.
        if(slow!=fast)return NULL;
        
        // Initialize slow = head and take fast as it is.
        // ansmove both pointer one node at a time.
        // the node at which both pointer meet, is the starting node of cycle.
        slow = head;
        while(slow!=fast){
            
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
  
    }
};
