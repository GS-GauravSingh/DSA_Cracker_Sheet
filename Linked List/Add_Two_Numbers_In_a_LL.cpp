class Solution
{

// Time complexity:- O(N+M), N => length of first LL, M => length of second LL.
// Space complexity:- O(max(N,M))

private:
//---------------- reverse function ---------------------------
    struct Node *reverse(struct Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (curr != NULL)
        {

            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
        return head;
    }
//------------------------------------------------------------

//------- Function to insert node at end -------------
    void insertAtEnd(struct Node *&head, struct Node *&tail, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
//-----------------------------------------------------

// ----------------- Add Function --------------------
    struct Node *add(struct Node *first, struct Node *second)
    {
        // 9+9 = 18
        // digit = 8 and carry = 1
        // digit = sum%10; and carry = sum/10;

        // Steps,
        // 1. carry = 0. //2. find sum. //3. find digit = sum%10;
        // 4. Create a node for digit. //5. find carry = sum/10;

        int carry = 0;
        Node *ansHead = NULL;
        Node *ansTail = NULL;

        while (first != NULL and second != NULL)
        {
            // this loop will break if both Linked List or any one of them become NULL

            int sum = first->data + second->data + carry;
            int lastDigit = sum % 10;

            // create a node for last digit.
            insertAtEnd(ansHead, ansTail, lastDigit);

            // set carry
            carry = sum / 10;

            // move pointers
            first = first->next;
            second = second->next;
        }

        // for remaining elements in first LL.
        while (first != NULL)
        {

            int sum = first->data + carry;
            int lastDigit = sum % 10;

            // create a node for last digit.
            insertAtEnd(ansHead, ansTail, lastDigit);

            // set carry
            carry = sum / 10;

            // move pointer
            first = first->next;
        }

        // for remaining elements in second LL.
        while (second != NULL)
        {

            int sum = second->data + carry;
            int lastDigit = sum % 10;

            // create a node for last digit.
            insertAtEnd(ansHead, ansTail, lastDigit);

            // set carry
            carry = sum / 10;

            // move pointer
            second = second->next;
        }

        // if carry is remaining.
        while (carry != NULL)
        {

            int sum = carry;
            int lastDigit = sum % 10;

            // create a node for last digit.
            insertAtEnd(ansHead, ansTail, lastDigit);

            // set carry
            carry = sum / 10;
        }

        // return ans
        return ansHead;
    }
    //----------------------------------------------------

public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        // Step 1: reverse both the linked list.
        first = reverse(first);
        second = reverse(second);

        // Step 2: perfrom addition from left (because LL's are reversed).
        Node *ans = add(first, second);

        // Step 3: reverse the final LL (ans).
        ans = reverse(ans);

        // Step 4: return ans
        return ans;
    }
};