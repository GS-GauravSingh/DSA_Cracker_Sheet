// Time complexity:- O(n)
// Space complexity:- O(1)

class Solution
{
private:
    Node *getTail(Node *head)
    {
        // Base Case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        return tail;
    }

    // Similar to 2-Sum question in arrays (sorted).
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head1, int target)
    {
        vector<pair<int, int>> ans;

        // Base Case
        if (head1 == NULL || head1->next == NULL)
        {
            return ans;
        }

        Node *tail = getTail(head1);

        Node *head = head1;

        while (head != tail)
        {

            int val_1 = head->data;
            int val_2 = tail->data;

            int sum = val_1 + val_2;

            if (sum == target)
            {
                ans.push_back({val_1, val_2});
                head = head->next;
            }
            else if (sum < target)
            {
                head = head->next;
            }
            else
            {
                tail = tail->prev;
            }
        }

        return ans;
    }
};