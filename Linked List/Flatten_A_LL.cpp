// Time Complexity:- O(M*N)
// Space Complexity:- O(N)


void insertAtEnd(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->bottom = newNode;
        tail = newNode;
    }
}

//---------------- merge 2 sorted linked list function ----------------
Node *merge_2_SortedLists(Node *child, Node *right)
{
    // Base case
    if (child == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return child;
    }

    // creating ans LL
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (child != NULL && right != NULL)
    {
        if (child->data < right->data)
        {
            int val = child->data;
            insertAtEnd(ansHead, ansTail, val);
            child = child->bottom;
        }
        else
        {
            int val = right->data;
            insertAtEnd(ansHead, ansTail, val);
            right = right->bottom;
        }
    }

    // if child list != NULL
    while (child != NULL)
    {

        int val = child->data;
        insertAtEnd(ansHead, ansTail, val);
        child = child->bottom;
    }

    // if right list != NULL
    while (right != NULL)
    {
        int val = right->data;
        insertAtEnd(ansHead, ansTail, val);
        right = right->bottom;
    }

    return ansHead;
}


// ------------------ flatten function ------------------
Node* flatten(Node *root)
{
    // Base case
    if (root == NULL || root->next == NULL)
    {
        return root;
    }

    // make a recursive call
    // first we go to the base case,
    // and merge the lists while returning from base case.
    Node *right = flatten(root->next);

    // pointer to child list
    Node *child = root;
    child->next = NULL;

    // merge 2 sorted lists
    Node *ans = merge_2_SortedLists(child, right);

    // return ans
    return ans;
}
