#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(1)
    int pivotIndex(vector<int> &nums)
    {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }

        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            totalSum -= nums[i];
            
            if (leftSum == totalSum)
            {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */
int main()
{
    vector<int> arr = {1, 7, 3, 6, 5, 6};

    Solution s;
    cout << "Pivot index: " << s.pivotIndex(arr) << endl;
}