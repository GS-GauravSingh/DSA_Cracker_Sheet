// Time Complexity of MergeSort:- O(n*log(n))
// Space Complexity of MergeSort:- O(n)

class Solution
{
private:
//-------------- function for finding middle element of LL --------------------------
    Node *findMid(Node *head)
    {
        // Base case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }


//------------------ function to insert node at end ---------------------------
    Node *insertAtEnd(Node *&head, Node *&tail, int data)
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

//----------------------- merge two sorted linked list -----------------------
    Node *merge(Node *left, Node *right)
    {
        // Base cases
        if (left == NULL)
        {
            return right;
        }
        if (right == NULL)
        {
            return left;
        }

        // variable for ans LL
        Node *ansHead = NULL;
        Node *ansTail = NULL;

        while (left != NULL && right != NULL)
        {

            if (left->data < right->data)
            {
                int value = left->data;
                insertAtEnd(ansHead, ansTail, value);

                // move currLeft pointer
                left = left->next;
            }
            else
            {
                int value = right->data;
                insertAtEnd(ansHead, ansTail, value);

                // move currRight pointer
                right = right->next;
            }
        }

        // if Left != NULL
        while (left != NULL)
        {
            int value = left->data;
            insertAtEnd(ansHead, ansTail, value);

            // move currLeft pointer
            left = left->next;
        }

        // if Right != NULL
        while (right != NULL)
        {
            int value = right->data;
            insertAtEnd(ansHead, ansTail, value);

            // move currRight pointer
            right = right->next;
        }
        return ansHead;
    }

public:

    // Function to sort the given linked list using Merge Sort.
    Node *mergeSort(Node *head)
    {
        // Base case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Step 1: find mid
        Node *mid = findMid(head);

        // Step 2:Break LL into 2 half, after finding mid.
        Node *left = head;
        Node *right = mid->next;

        mid->next = NULL; // this will seperate the LL

        // Step 3: make a recursive call on left and right half
        left = mergeSort(head);
        right = mergeSort(right);

        // Step 4: merge two sorted Linked List
        Node *ans = merge(left, right);

        // Step 5: return ans
        return ans;
    }
};