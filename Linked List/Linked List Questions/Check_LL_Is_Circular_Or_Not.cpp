// Time complexity:- O(n)
// Space complexity:- O(1)

bool isCircular(Node *head)
{
    // Base Case
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    Node *temp = head->next;

    while (temp != head && temp != NULL)
    {
        temp = temp->next;
    }

    // if temp == head, it means Linked List is circular i.e., last Node points to head.
    if (temp == head)
    {
        return true;
    }
    // else, temp points to NULL means it is not circular i.e., last Node points to NULL.
    return false;
}