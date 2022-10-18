// Note:- There are 8 possible ways to solve this problem.

// -- Function to find intersecting point using additional data structure --

// Time Complexity:- O(n) to insert element in set, + O(m) to traverse second LL. => O(M+N)
// Space Complexity:- O(n)
int findIntersection_Using_set(Node *head1, Node *head2)
{

    unordered_set<Node *> s;
    while (head1 != NULL)
    {
        s.insert(head1);
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        if (s.find(head2) != s.end())
        {
            return head2->data;
        }

        head2 = head2->next;
    }
    return -1;
}
// This will give TLE Error

// -----------------------------------------------------------------------------

// ----------------------using 2-pointer approach -----------------------------
// Using Two pointers : Explaination

// Initialize two pointers ptr1 and ptr2  at head1 and  head2.
// Traverse through the lists, one node at a time.
// When ptr1 reaches the end of a list, then redirect it to head2.
// similarly, when ptr2 reaches the end of a list, redirect it to the head1.
// Once both of them go through reassigning, they will be equidistant from
//  the collision point
// If at any node ptr1 meets ptr2, then it is the intersection node.
// After the second iteration if there is no intersection node it returns NULL.


// Time Complexity:- O(m + n), m and n are length of linked lists.
// Space Complexity:- O(1)

int findIntersectingPoint_Using_2_pointer(Node *head1, Node *head2)
{

    Node *a = head1;
    Node *b = head2;

    while (a != b)
    {

        if (a == NULL)
        {
            a = head2;
        }
        else
        {
            a = a->next;
        }

        if (b == NULL)
        {
            b = head1;
        }
        else
        {
            b = b->next;
        }
    }

    return a->data;
}

// Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
    return findIntersectingPoint_Using_2_pointer(head1, head2);
}