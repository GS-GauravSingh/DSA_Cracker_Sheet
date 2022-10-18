// Approach 1: store the count of 0,1, and 2 and insert it in LL (code below).
// Approach 2: create a spwerate LL for 0,1 and 2 and merge all of them.
// both the approachs having same Time and Space complexity you can use any one of them;

class Solution
{

    // Time Complexity:- O(n)
    // Space Complexity:- O(1)

public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        // variable to store count of 0's, 1's and 2's
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;

        // Step 1: store count of 0,1 and 2.
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == 0)
            {
                zeroCount++;
            }
            else if (temp->data == 1)
            {
                oneCount++;
            }
            else
            {
                twoCount++;
            }
            temp = temp->next;
        }

        // Step 2: treavese the LL and first insert 0, then 1 and then 2.
        temp = head;
        while (temp != NULL)
        {

            if (zeroCount)
            {
                temp->data = 0;
                zeroCount--;
            }
            else if (oneCount)
            {
                temp->data = 1;
                oneCount--;
            }
            else
            {
                temp->data = 2;
                twoCount--;
            }
            temp = temp->next;
        }
        return head;
    }
};
