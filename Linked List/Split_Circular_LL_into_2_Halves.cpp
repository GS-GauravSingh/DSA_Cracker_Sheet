// Time Complexity:- O(n), n is the number of node in LL.
// Space Complexity:- O(1)

//--------------- Get Middle Node Function, TC:- O(n), Sc:-O(1) ---------
Node *getMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    // loop condition is, fast != head && fast -> next != head
    // because the LL is circular so there will no such node that points to NULL.
    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//--------------- Get Last Node Function, TC:- O(n), Sc:-O(1) ---------
Node *lastNode(Node *head)
{
    Node *temp = head->next;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    return temp;
}

//--------------- Split Function, TC:- O(n), Sc:-O(1) ---------
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // Base case
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    if (head->next == head)
    {
        return;
    }

    // Step 1: get the middle node.
    Node *mid = getMid(head);

    // Step 2: split the LL into two half
    //  1st half is from head to mid and 2nd from mid->next to end;

    Node *firstHead = head;
    Node *firstTail = mid;

    Node *secondHead = mid->next;
    // get the last node for second half.
    Node *secondTail = lastNode(head);

    // Step 3: make connextion to make both linked List circular.
    firstTail->next = firstHead;
    secondTail->next = secondHead;

    // Step 4: return answers
    *head1_ref = firstHead;
    *head2_ref = secondHead;
}