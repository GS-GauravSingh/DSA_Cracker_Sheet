#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    /* Brute Force Approach:- Using Nested Loops. */
    // Time Complexity:- O(n^2)
    // Space Complexity:- O(1)
    int numPairsDivisibleBy60_Brute_Force(vector<int> &time)
    {
        int n = time.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int a = time[i];
                int b = time[j];
                int totalDuration = a + b;
                if (totalDuration % 60 == 0)
                {
                    count++;
                }
            }
        }

        return count;
    }

    /* Optimized Approach:- . */
    // Time Complexity:- O()
    // Space Complexity:- O(1)
    int numPairsDivisibleBy60(vector<int> &time)
    {
        
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */
int main()
{
    vector<int> time = {30, 20, 150, 100, 40};

    Solution s;
    cout << s.numPairsDivisibleBy60(time);
}