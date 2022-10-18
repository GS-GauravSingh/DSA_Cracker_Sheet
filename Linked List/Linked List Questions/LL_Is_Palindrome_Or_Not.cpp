// Time complexity:- O(n)
// Space complexity:- O(1)

class Solution
{
private:
    //-------------Reverse Function, TC:-O(n) ---------------------
    Node *reverse(Node *head)
    {
        Node *currNode = head;
        Node *prevNode = NULL;
        Node *nextNode = NULL;

        while (currNode != NULL)
        {

            nextNode = currNode->next;
            currNode->next = prevNode;

            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

    //-------------Get Middle Node Function, TC:-O(n) ---------------------
    Node *getMid(Node *head)
    {
        Node *slow = head;
        // fast ko head -> next pr isliye kr rhe hai kyuki, agar head se start kiya,
        // toh appko LL mid Node se hi reverse krni padegi or agar head -> next se start
        // kiya to hume LL mid -> next se reverse krni padegi jisske ki hum baad me change revert bhi kr skte hai.

        // ex:- 1->2->2->1 ==> even length LL, (fast = head) mid node = 2 (right one).
        // (fast = head -> next) mid node = 2 (left one).

        // ex:- 1->2->3->2->1 == odd length LL, (fast = head) mid node = 3.
        // (fast = head -> next) mid node = 3.
        Node *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:

    //------------- Check Palindrome Function, TC:- O(n) ---------------------
    bool isPalindrome(Node *head)
    {
        // Base Case
        if (head == NULL || head->next == NULL)
        {
            return true;
        }

        // Step 1: get the middle node of Linked List
        Node *mid = getMid(head);

        // Step 2: reverse the Linked List from mid -> next to end.
        Node *middleNode = mid;
        Node *reverseHead = reverse(mid->next);

        // linking mid to reverse ll after mid.
        middleNode->next = reverseHead;

        // Step 3: compare both halves
        Node *head1 = head;
        Node *head2 = reverseHead;

        while (head2 != NULL)
        {

            if (head1->data != head2->data)
            {
                return false;
            }
            else
            {
                head1 = head1->next;
                head2 = head2->next;
            }
        }

        // Step 4: (Optional Step) if program is out of the above loop it means LL is palindrome.
        //  So, before returning true, revert the changes you've done in the LL.

        middleNode->next = reverse(mid->next);

        // Step 5: return true
        return true;
    }
};