// Approach 1: using selection sort technique.
//  Time complexity:- O(n^2)
//  Space complexity:- O(1)

//----------- Approach 1 :- Code -------------------------------------
Node *sortedDll(Node *head, int k)
{
    Node *currNode = head;
    Node *nextNode = NULL;

    while (currNode->next != NULL)
    {
        nextNode = currNode->next;

        while (nextNode != NULL)
        {
            if (currNode->data > nextNode->data)
            {
                swap(currNode->data, nextNode->data);
            }
            nextNode = nextNode->next;
        }

        currNode = currNode->next;
    }
    return head;
}
//---------------- Approach 1 ends here.------------------------------


//----------------------- Approach 2 ---------------------------------

// Approach 2: using insertion sort technique.
//  Time complexity:- O(n*k)
//  Space complexity:- O(1)

Node *sortedDll(Node *head, int k)
{
    // variable to traverse the dll;
    // Traverse the dll till current != NULL
    Node *currNode = head;

    while (currNode != NULL)
    {
        // we have to compare the data of current node to previous node.
        // in case of sorted list, curr->data is always > prev -> data;
        // ex:- 1->2->3->4->NULL,every current element is greater that its previous element in sorted list.

        // So, in inertions sort,
        // we pick one element and in previous direction we insert that element at ther correct position.
        Node *prevNode = currNode->prev;
        int key = currNode->data;

        while (prevNode != NULL && key < prevNode->data)
        {
            // Shift value
            prevNode->next->data = prevNode->data;
            // move prev
            prevNode = prevNode->prev;
        }

        // while shifting values if our prevNode points to NULL
        // it means the correct position of the key is our head node.
        if (prevNode == NULL)
        {
            // place key at its correcto position
            head->data = key;
        }
        else
        {
            // else the correct position of the key is somewhere int the middle.
            // in that case, or prev node will always point to one node before the key's correct position.
            // place key at position prevNode -> next -> data = key;
            prevNode->next->data = key;
        }

        // move curr pointer.
        currNode = currNode->next;
    }
    return head;
}
//---------------- Approach 2 ends here.------------------------------



//-------------------------- Approach 3 ------------------------------
// Approach 3: We can sort the list using the MIN HEAP data structure. 
//  Time complexity:- O(n log(k))
//  Space complexity:- O(k)

// Note:- I will get back to this approach after some time.