// Time Complexity:- O(n)
// Space Complexity:- O(n) because of unordered_map.


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        // Base Case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // map to check is element is repeated or not.
        unordered_map<int, bool> visited;
        
        Node* temp = head;
        Node* prev = NULL;
        
        while(temp != NULL){
            
            int value = temp -> data;
            
            if(visited[value]){
                
                // means duplicate element.
                if(temp -> next == NULL){
                    prev -> next = NULL;
                    delete temp;
                }
                else{
                    Node* nodeToDelete = temp;
                    prev->next = temp->next;
                    nodeToDelete -> next = NULL;
                    delete nodeToDelete; 
                }
                
            }
            else{
                // unique element.
                // we have to set our prev pointer and update map.
                visited[value] = true;
                prev = temp;
            }
            
            temp = prev -> next;
        }
        
        return head;
    }
};
