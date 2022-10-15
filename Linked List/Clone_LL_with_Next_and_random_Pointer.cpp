// Approach 1: Using map data structure.
// Time Complexity:- O(n)
// Space Complexity:- O(n)

class Solution
{
private:
    //---------------- inserting nodes in clone list ------------------------
    Node *insert(Node *&head, Node *&tail, int data)
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

    //---------------- making a copy of list with next pointer -------------
    Node *clone_List_With_Next_Pointer(Node *head)
    {
        // Base case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Creating a list
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        Node *temp = head;
        while (temp != NULL)
        {
            insert(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        return cloneHead;
    }

public:
    Node *copyList(Node *head)
    {
        // Base case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Data structure to store mapping of original list node to clone list node
        unordered_map<Node *, Node *> mapping;

        // creating clone list with next pointer
        Node *cloneHead = clone_List_With_Next_Pointer(head);

        // store mappings, original node map to clone node.
        Node *cloneNode = cloneHead;
        Node *originalNode = head;

        while (originalNode != NULL && cloneNode != NULL)
        {
            mapping[originalNode] = cloneNode;

            // move pointers
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // copy random pointers
        // cloneNode -> random = mapping[originalNode -> random]
        cloneNode = cloneHead;
        originalNode = head;

        while (cloneNode != NULL)
        {
            cloneNode->arb = mapping[originalNode->arb];
            // move pointers
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // return clone list
        return cloneHead;
    }
};

// Approach 2: without Using map data structure.
// Time Complexity:- O(n)
// Space Complexity:- O(1)
class Solution
{
private:
    //---------------- inserting nodes in clone list ------------------------
    Node *insert(Node *&head, Node *&tail, int data)
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

    //---------------- making a copy of list with next pointer -------------
    Node *clone_List_With_Next_Pointer(Node *head)
    {
        // Base case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Creating a list
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        Node *temp = head;
        while (temp != NULL)
        {
            insert(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        return cloneHead;
    }

public:
    Node *copyList(Node *head)
    {
        // Base case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Step 1:- creating clone list with next pointer
        Node *cloneHead = clone_List_With_Next_Pointer(head);

        // Step 2:- add cloneNode in between original list nodes
        Node *originalNode = head;
        Node *cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL)
        {
            Node *next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

        // Step 3:- copy random pointers
        Node *temp = head;
        while (temp != NULL)
        {
            // agar temp -> next == NULL or aap temp -> next ka random nikalne ki koshis kroge
            // toh segementation fault aayega.
            if (temp->next != NULL)
            {
                // agar temp -> random == NULL or aap random ka next nikalne ki koshis kroge
                // toh segementation fault aayega
                if (temp->arb != NULL)
                {
                    temp->next->arb = temp->arb->next;
                }
                else
                {
                    temp->next->arb = NULL;
                }

                // above condition in one line,
                // temp -> next -> arb = temp -> arb ? temp -> arb -> next : temp -> arb;
            }

            // because we want to traverse original list
            temp = temp->next->next;
        }

        // Step 4:- revert changes done in step 2
        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL)
        {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if (originalNode != NULL)
            {
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }

        // Step 5:- return ans
        return cloneHead;
    }
};