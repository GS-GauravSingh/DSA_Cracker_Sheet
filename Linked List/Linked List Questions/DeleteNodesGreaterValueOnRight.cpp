// Approach 1: using two loops
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)

class Solution
{

public:
    Node *compute(Node *head)
    {
        // Base case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *curr = head;
        while (curr != NULL)
        {

            Node *nextNode = curr->next;
            bool found = false;

            while (nextNode != NULL)
            {
                if (nextNode->data > curr->data)
                {
                    found = true;
                    break;
                }
                else
                {
                    nextNode = nextNode->next;
                }
            }

            if (found == true)
            {
                // means there exists a value which is greater then curr,
                // in that case we have to delete curr node;
                Node *nodeToDelete = curr->next;
                // curr -> next ke data ko copy krlo curr me
                // or fir curr -> next ko delete krdo.

                curr->data = curr->next->data;

                // make connections
                curr->next = curr->next->next;

                delete nodeToDelete;
            }
            else
            {
                // means, rest of the element are smaller than curr,
                // in that case simply move curr pointer.
                curr = curr->next;
            }
        }

        // return ans
        return head;
    }
};
//--------------Approach 1 ends here. -----------------------------------

// Approach 2 (Optimized): using reverse
// Time Complexity:- O(n)
// Space Complexity:- O(1)

class Solution
{

private:
    Node *reverse(Node *head)
    {
        Node *prevNode = NULL;
        Node *currNode = head;
        Node *nextNode = NULL;

        while (currNode != NULL)
        {

            nextNode = currNode->next;
            currNode->next = prevNode;

            // move pointers
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

public:
    Node *compute(Node *head)
    {

        // Base case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // reverse Linked List
        head = reverse(head);

        // ex 12 -> 15 -> 10 -> 11 -> 5 -> 6 -> 2 -> 3 -> NULL

        // step 1: reverse LL
        // after reverse it would look like this,
        //  3 -> 2 -> 6 -> 5 -> 11 -> 10 -> 15 -> 12 -> NULL

        // Step 2: start treaversing the list and maintain a variable max;
        //  initialize max = head -> data; i.e., max = 3;

        // while traversing we simply check if curr -> data is less than max,
        // it means there exist a value on rightsize of curr, that is greater that curr.
        // in this case simply delete current.

        // above example,
        // max = 3; when curr = 2, then we have to delete node 2.
        // in above question we simly see that there exists a value on,
        // the right size of 2 which is greater that 2.
        // and so on..

        Node *curr = head->next;
        Node *prev = head;
        int max = head->data;

        while (curr != NULL)
        {
            if (curr->data >= max)
            {
                // if curr -> data is  >= max, means there is not such element,
                // on the right size which is greater the curr all elements are smaller than curr.
                // in this case, update max, prev and curr.
                max = curr->data;
                prev = curr;
                curr = curr->next;
            }
            else
            {
                // means there exists a value greater that max.
                // simply delete curr
                Node *del = curr;
                prev->next = curr->next;

                // move curr pointer
                curr = prev->next;

                delete del;
            }
        }

        // reverse the list and return
        head = reverse(head);
        return head;
    }
};

//--------------Approach 2 ends here. -----------------------------------
