// Time Complexity:- O(n)
// Space Complexity:- O(1)

//----------- Function to delete a given node from the list --------------------

struct Node *Delete_Node(struct Node *head, int key)
{

    // we have to delete key from circular LL
    Node *temp = head;

    // So, to delete a node we need two pointer
    // 1st pointer points to the node which i want to delete.
    // 2nd pointer points to the previous node of that node which i want to delete.
    Node *curr = temp;
    Node *prev = NULL;

    while (curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }

    Node *nodeToDelete = curr;
    prev->next = curr->next;
    nodeToDelete->next = NULL;
    delete nodeToDelete;

    return head;
}
// ---------- Function to reverse the linked list ----------------
void reverse(struct Node **head_ref)
{
    Node *head = *head_ref;

    // Base case
    if (head->next == head)
    {
        return;
    }

    Node *prevNode = NULL;
    Node *currNode = head;
    Node *nextNode = NULL;

    do
    {
        nextNode = currNode->next;
        currNode->next = prevNode;

        // move pointers
        prevNode = currNode;
        currNode = nextNode;
    } while (currNode != head);

    // Important Step
    // when LL is reverse, it become singly LL because the connection from last node to head node is broke.
    // we have to link last node with head node.
    currNode->next = prevNode;

    // return reverse LL
    *head_ref = prevNode;
}

//-------------------- Driver function ------------------------
void deleteNode(struct Node **head, int key)
{
    *head = Delete_Node(*head, key);
}