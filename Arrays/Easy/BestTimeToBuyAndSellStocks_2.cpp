#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(1)
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            int buy = prices[i];
            int sell = prices[i + 1];

            if (buy < sell)
            {
                profit += sell - buy;
            }
        }

        return profit;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */
int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};

    Solution s;
    cout << s.maxProfit(arr);
}