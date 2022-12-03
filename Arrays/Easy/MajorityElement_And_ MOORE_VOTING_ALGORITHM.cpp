#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    /* Brute Force Approac:- Using unordered_map. */
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(n)
    int majorityElement_BruteForce(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }

        int appear = n / 2; // if any element appear more then n/2 time, that element si the majority element.
        for (auto it : mpp)
        {
            if (it.second > appear)
            {
                return it.first;
            }
        }

        return -1;
    }

    /* Optimized Approach:- Using Moore Voting Algorithm. */
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(1)
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();

        int count = 0;
        int element = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                count++;
                element = nums[i];
            }
            else if (nums[i] == element)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return element;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */
int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};

    Solution s;
    cout << s.majorityElement(arr);
}