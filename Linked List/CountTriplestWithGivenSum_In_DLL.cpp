// Time Complexity:- O(n^2) 
// Auxiliary Space:- O(1)



// Function to count pairs whose sum equal to pairSum
int countPairs(DLLNode *startNode, DLLNode *endNode, int pairSum)
{
    int count = 0;
    // The loop terminates when either of two pointers become NULL,
    // or they cross each other (second->next == first),
    // or they become same (first == second)
    while (startNode != NULL && endNode != NULL && startNode != endNode && endNode->next != startNode)
    {
        if ((startNode->data + endNode->data) == pairSum)
        {
            count++;
            startNode = startNode->next;
            endNode = endNode->prev;
        }

        else if ((startNode->data + endNode->data) > pairSum)
        {
            endNode = endNode->prev;
        }

        else
        {
            startNode = startNode->next;
        }
    }

    // Required count of pairs
    return count;
}

int countTriplets(DLLNode *head, int tripletSum)
{
    // Base case
    if (head == NULL)
    {
        return 0;
    }

    DLLNode *currentNode, *startNode, *lastNode;
    int count = 0;
    lastNode = head;
    // get last node of DLL
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    for (currentNode = head; currentNode != NULL; currentNode = currentNode->next)
    {
        // i don't know why this shows error when i tru to use while loop instead of for loop
        startNode = currentNode->next;
        count += countPairs(startNode, lastNode, tripletSum - currentNode->data);
    }

    // Return count of triplets
    return count;
}