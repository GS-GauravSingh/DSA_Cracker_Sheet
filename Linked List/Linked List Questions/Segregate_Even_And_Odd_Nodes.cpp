// Time Complexity:- O(n)
// Space Complexity:- O(1)

class Solution
{

public:
    Node *divide(int N, Node *head)
    {
        // code here
        Node *oddHead = NULL;
        Node *oddTail = NULL;

        Node *evenHead = NULL;
        Node *evenTail = NULL;

        // inserting odd and even nodes.
        Node *curr = head;
        while (curr != NULL)
        {
            int x = curr->data;
            if (x & 1)
            {
                // odd node
                Node *newNode = new Node(x);
                if (oddHead == NULL)
                {
                    oddHead = oddTail = newNode;
                }
                else
                {
                    oddTail->next = newNode;
                    oddTail = newNode;
                }
            }
            else
            {
                // even Node
                Node *newNode = new Node(x);
                if (evenHead == NULL)
                {
                    evenHead = evenTail = newNode;
                }
                else
                {
                    evenTail->next = newNode;
                    evenTail = newNode;
                }
            }

            // move curr pointer
            curr = curr->next;
        }

        if (oddTail != NULL)
        {
            oddTail->next = NULL;
        }

        if (evenHead == NULL)
        {
            return oddHead;
        }
        else
        {
            evenTail->next = oddHead;
        }

        return evenHead;
    }
};
