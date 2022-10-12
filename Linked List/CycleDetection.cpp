// Brute Force :- use hash map, if LL contains loop, then there are repeting nodes, else no repeting nodes.
// Time Complexity:- O(n)
// Space Complexity:- O(n)


// I'm using floyd cucle detection algorithm to solve this ploblem.

// Time Complexity:- O(n)
// Space Complexity:- O(1)
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
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
};
