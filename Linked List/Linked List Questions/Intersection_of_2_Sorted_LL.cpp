// ques:- Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.
// Note: The list elements are not necessarily distinct.

// ex:- first => 1->2->3->4->6->NULL
//     second => 2->4->6->8->NULL
//  output:-    2->4->6

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

Node *findIntersection(Node *head1, Node *head2)
{
    // variable to traverse an first and second list.
    Node *first = head1;
    Node *second = head2;

    // variable to create an ans list
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            first = first->next;
        }
        else if (first->data > second->data)
        {
            second = second->next;
        }
        else
        {
            // if both are equal, means we've found the intersecting element.
            // create a node for this element.
            // and increment both pointers.
            int element = first->data;
            insertAtEnd(ansHead, ansTail, element);

            // move both pointers
            first = first->next;
            second = second->next;
        }
    }

    // return the answer,
    return ansHead;
}