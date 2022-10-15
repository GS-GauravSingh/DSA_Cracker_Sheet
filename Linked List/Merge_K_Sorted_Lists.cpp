//------------------ Recursive approach ---------------------------------------

// Time Complexity:- O(n*k)
// Space Complexity:- O(n)


class Solution
{
private:
    Node *merge(Node *left, Node *right)
    {
        // Base cases
        if (left == NULL && right == NULL)
        {
            return NULL;
        }
        if (left == NULL)
        {
            return right;
        }
        if (right == NULL)
        {
            return left;
        }

        // variable for ans LL
        Node *ans = new Node(-1);
        Node *tail = ans;

        while (left != NULL && right != NULL)
        {

            if (left->data < right->data)
            {
                tail->next = left;
                tail = left;

                // move Left pointer
                left = left->next;
            }
            else
            {
                tail->next = right;
                tail = right;

                // move Right pointer
                right = right->next;
            }
        }

        if (left == NULL)
        {
            tail->next = right;
        }

        if (right == NULL)
        {
            tail->next = left;
        }

        return ans->next;
    }

    Node *merge_k_LinkedLists(Node *arr[], int i, int k)
    {
        if (i == k - 1)
        {
            Node *lastList = arr[i];
            return lastList;
        }

        Node *second = merge_k_LinkedLists(arr, i + 1, k);

        Node *currentList = arr[i];

        Node *ans = merge(second, currentList);

        return ans;
    }

public:
    // Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int K)
    {
        // Base Cases
        if (K == 0)
        {
            return NULL;
        }
        if (K == 1)
        {
            return arr[0];
        }

        int i = 0;
        return merge_k_LinkedLists(arr, i, K);

        // or you can replace the above recursive function using the below for loop

        // Node* ans = arr[0];
        // for(int i=1; i<K; i++){
        //     ans = merge(ans, arr[i]);
        // }
        // return ans;
    }
};