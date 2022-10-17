// Time Complexity:- O(n)
// Space Complexity:- O(1)

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

// Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    // reverse the list, because we heav to find nth node from the end of linked list.
    head = reverse(head);

    // we know if i want to reach to nth node, we have to move n-1 times
    int move = n - 1;

    Node *curr = head;
    while (curr != NULL && move)
    {
        curr = curr->next;
        move--;
    }
    if (curr != NULL)
    {
        return curr->data;
    }
    else
    {
        return -1;
    }
}
