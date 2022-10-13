//----------------------- merge two sorted linked list -----------------------


//Time Complexity: O(N+M) where N and M are the sizes of linked lists.
//Space Complexity: O(N+M)/ size of ans list.


void insertAtEnd(node *&head, node *&tail, int data)
{
    node *newNode = new node(data);
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

node *merge(node *left, node *right)
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
    node *ansHead = NULL;
    node *ansTail = NULL;

    while (left != NULL && right != NULL)
    {

        if (left->data < right->data)
        {
            int value = left->data;
            insertAtEnd(ansHead, ansTail, value);

            // move Left pointer
            left = left->next;
        }
        else
        {
            int value = right->data;
            insertAtEnd(ansHead, ansTail, value);

            // move Right pointer
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