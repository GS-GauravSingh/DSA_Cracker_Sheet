// Time Complexity:- O(n), n is the number of nodes in DLL.
// Space Complexity:- O(1)


//-------- Function to Reverse Doubly Linked List ----------------------------
Node *reverseDLL(Node *head)
{
    // Base Case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prevNode = NULL;
    Node *currNode = head;
    Node *nextNode = NULL;

    while (currNode != NULL)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;

        // In case of DLL we have to handle the previous pointer also.
        currNode->prev = nextNode;

        // move pointers
        prevNode = currNode;
        currNode = nextNode;
    }

    return prevNode;
}
//-----------------------------------------------------------------------------