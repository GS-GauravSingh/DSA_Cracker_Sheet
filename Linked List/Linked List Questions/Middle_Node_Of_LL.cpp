// Time Complexity: O(N/2) = O(N)
// Space Complexity: O(1)

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        // Base Case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Two pointer approach.
        // Slow move 1 noda at a time, fast move 2 node at a time.
        // When your fast pointer points to NULL, then your slow pointer is at the middle node of Linkd List.
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }
        return slow; // or you can return fast also.
    }
};