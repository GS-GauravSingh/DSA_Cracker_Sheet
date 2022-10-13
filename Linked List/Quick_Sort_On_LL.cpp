// Quick Sort.
//Time Complexity:- Best Case O(n log n) and in Worst Case O(n^2)
//Space Complexity:- O(log n)



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

//----------------------- merge two sorted linked list -----------------------
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

            // move currLeft pointer
            left = left->next;
        }
        else
        {
            int value = right->data;
            insertAtEnd(ansHead, ansTail, value);

            // move currRight pointer
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


// ------------------------- Partition ----------------------------
node *partition(node *head)
{
    // set pivot element
    node *pivot = head;

    // now we have to swap value such that,
    // all value which are less then pivot are appear on the left side of the pivot and
    // all value which are greater then pivot are appear on the right side of the pivot.
    // after this pivot is at it right position.

    // variable to traverse the LL
    // starting from head -> next because we choose head -> data as our pivot element.
    node *curr = head->next;
    node *prev = head; // node to swap value less than pivot

    while (curr != NULL)
    {
        // ex 20->9->7->6->10
        // pivot = 20, prev points to 20, curr points to 9

        // Note:- saara khel yahi hai,pivot ko uski sahi position me le jaane ke liye.
        // whenever you find value which is less than pivot, just swap it with pivot.
        // in above ex:-
        // 9<20 swap(prev, pivot) ==> 9->20->7->6->10
        // pivot = 20, prev points to 20, curr points to 7

        // 7<20 swap(prev, pivot) ==> 9->7->20->6->10
        // pivot = 20, prev points to 20, curr points to 6

        // 6<20 swap(prev, pivot) ==> 9->7->6->20->10
        // pivot = 20, prev points to 20, curr points to 10

        // 10<20 swap(prev, pivot) ==> 9->7->6->10->20
        // pivot = 20, prev points to 20, curr points to NULL

        // pivot placed to its correct position.

        if (curr->data < pivot->data)
        {
            swap(prev->data, pivot->data);
            prev = prev->next;
        }
        curr = curr->next;
    }
    return pivot;
}

//----------------------------------------------------------------


//-------------Quick sort function -------------------------------
node* Quick_Sort(node *head)
{
    // Base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Partition
    node *p = partition(head);
    node *left = head;
    node *right = p->next;
    p->next = NULL;

    // recursive call on left and right half
    left = Quick_Sort(left);
    right = Quick_Sort(right);

    // merge 2 sorted linked lists
    node *ans = merge(left, right);

    // return ans
    return ans;
}

void quickSort(struct node **headRef)
{
    node *head = *headRef;
    node *ansHead = Quick_Sort(head);
    *headRef = ansHead;
}