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
        int buy = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            buy = min(buy, prices[i]);
            profit = max(profit, prices[i] - buy);
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