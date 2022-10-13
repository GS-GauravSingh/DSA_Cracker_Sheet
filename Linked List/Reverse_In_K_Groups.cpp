/*-------------------- Recursive Solution ---------------------------------*/

// Time Complexity: O(n), n is number of nodes.
// Space Complexity: O(n/k).

class Solution
{
    public:
    struct node *reverse (struct node* head, int k)
    { 
        // Base Case
        if(head == NULL || head -> next == NULL || k == 1){
            return head;
        }
        
        // Step 1: Reverse 1-k nodes
        node* prevNode = NULL;
        node* currNode = head;
        node* nextNode = NULL;
        
        int inc = 0;
        while(currNode != NULL and inc <= k-1){
            
            nextNode = currNode -> next;
            currNode->next = prevNode;
            
            prevNode = currNode;
            currNode = nextNode;
            
            // increment the inc.
            inc++;
        }
        // after reversing, your prevNode will be your new Head.
        // and head will become tail of Linked List.
        // and nextNode will be your head of next k - group.
        
        //Step 2: make a recursive call for rest of the Linked list.
        if(nextNode != NULL){
            node* reverseHead = reverse(nextNode, k);
            //because after reversal, head will become tail node.
            head -> next = reverseHead;
        }
        
        return prevNode;
    }
};
/*-------------------- Recursive Solution Ends Here. ---------------------------------*/


/*-------------------- Iterative Solution ---------------------------------*/
// TC (proof) :- outer loop runs (n/k)time and inner loop runs k time.
// TC = (n/k) * k
// TC = O(n).

// Time Complexity: O(n).
// Space Complexity: O(1).

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Base Case
        if(head == NULL || head -> next == NULL || k == 1){
            return head;
        }
        
        //Step 1: create a dummy node and point it to head;
        node* dummy = new node(-1);
        dummy->next = head;
        
        // Step 2: Initializing pointers
        node* prevNode = dummy;
        node* currNode = dummy;
        node* nextNode = dummy;
        
        // Step 3: claculate the length of Linked List
        node* temp = head;
        int len = 0;
        while(temp != NULL){
            temp = temp -> next;
            len++;
        }
        
        // Step 4: Iterate the LL till nextNode != NULL.
        while(nextNode != NULL){
            // currNode points to head node.
            currNode = prevNode -> next;
            // nextNode points to head->next.
            nextNode = currNode -> next;
            
            // step 5: create a variable that store how many time we have to loop.
            int toLoop;
            if(len > k){
                // if length of LL is > k, the simply reverse k nodes and
                // dencrement len by k i.e., (len - k).
                toLoop = k;
            }
            else{
                // else, length of LL is < k, the simply reverse (len) nodes.
                toLoop = len;
            }
            
            
            
            // Step 6: Reverse most IMP part (not same as normal reverse).
            //ex k=3, 1->2->3->4->5->6->7->8->NULL
            // len = 8;
            //reverse Steps;
            
            //curr->next = next->next;
            //next->next = prev->next;
            //prev->next = next;
            //next = curr->next;
            
            // Behind the Scenes
            // curr = 1, prev = (-1) dummy node, next = curr->next (2);
            
            // 1->2->3 => 1->3   curr->next = next->next;
            // 1 <- 2 =>  next->next = prev->next;
            
            // LL will look like this, 3 <- 1 <- 2.
            //(-1) = dummy node, (prev->next = head)
            
            // (-1) -> 2 => ,  prev->next = next; 
            
            // LL will look like this (-1) -> 2 -> 1 -> 3.
            
            // next (2) = curr->next (3) 
            
            // dry run these steps for better understanding.

            for(int i = 1; i < toLoop; i++){
                currNode -> next = nextNode -> next;
                nextNode -> next = prevNode -> next;
                prevNode -> next = nextNode;
                nextNode = currNode -> next;
            }
            
            // Step 7: move prev to curr
            prevNode = currNode;
            
            //Step 8: decrement k for len;
            len = len - k;

        }
        
        return dummy->next;
        
    }
};

/*-------------------- Iterative Solution Ends Here. ---------------------------------*/
