#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    /* Brute Force Method 1:- Use sorting (so the duplicate element come together).*/
    // Time Complexity:- O(n log(n))
    // Space Complexity:- O(1)
    
    /* Brute Force Method 2:- Use Hashing */
    // Time Complexity:- O(n)
    // Space Complexity:- O(n)

    /* Optmized Approach:- Using Linked List Cycle Method. */
    // Time Complexity:- O(n)
    // Space Complexity:- O(1)
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        
    }
};

/*-------------------------- Solution Class Ends Here. ------------------------- */
int main()
{
    vector<int> arr = {1, 3, 4, 2, 2};

    Solution s;
    cout<<s.findDuplicate(arr);

}