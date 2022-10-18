/*-------------------- Recursive Solution ---------------------------------*/

// Time Complexity: O(n), n is number of nodes.
// Space Complexity: O(n/k).

Node* reverseDLLInGroups(Node* head, int k)
{	
    //Base Case
    if(head == NULL || head -> next == NULL || k == 1){
        return head;
    }
    
    //Step 1: reverse 1-k node
    Node* prevNode = NULL;
    Node* currNode = head;
    Node* nextNode = NULL;
    
    int inc = 0;
    while(currNode != NULL && inc <= k-1){
        nextNode = currNode -> next;
        currNode -> next = prevNode;
        currNode -> prev = nextNode;
        
        //move pointer
        prevNode = currNode;
        currNode = nextNode;
        
        //inclement inc pointer. So, that list wil reverse in K groups
        inc++;
    }
    // 1-k nodes  reverse after this loop
    // prevNode will be your head of reverse DLL.
    // and nextNode will be your head of next k group.
    
    //Step 2: make a recursive call on rest of the DLL.
    if(nextNode != NULL){
        Node* reverse = reverseDLLInGroups(nextNode, k);
        // connect this reverse list to firt k-group.
        head -> next = reverse;
        // because after reversal, head will become tail node.
    }
    return prevNode;
}

/*-------------------- Recursive Solution Ends Here. ---------------------------------*/