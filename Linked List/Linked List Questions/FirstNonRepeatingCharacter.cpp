// Time Complexity: O(26 * n)
// Space Complexity: O(26)


class Solution
{
public:
    string FirstNonRepeating(string A)
    {

        // vector to store frequency on characters
        vector<int> visited(26, 0);

        // vector to maintain order of characters
        vector<char> order;

        // string variable to store ans
        string ans = "";

        int n = A.length();

        for (int i = 0; i < n; i++)
        {

            if (visited[A[i] - 'a'] == 0)
            {
                // unique char
                order.push_back(A[i]);
            }
            // increment the frequency of inserted char
            visited[A[i] - 'a']++;

            // this loop alway start from 0, means
            // it will insert first non repeating character in the answer.
            int flag = 0;
            for (int j = 0; j < order.size(); j++)
            {
                if (visited[order[j] - 'a'] == 1)
                {
                    ans.push_back(order[j]);
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};