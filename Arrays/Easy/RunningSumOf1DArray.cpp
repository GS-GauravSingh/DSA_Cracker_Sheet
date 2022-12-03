#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:

    // Time Complexity:- O(n)
    // Space Complexity:- O(1)
    vector<int> runningSum(vector<int> &nums)
    {
        // Base Case
        if(nums.size() == 0 || nums.size() == 1){
            return nums;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            nums[i] = sum;
        }

        return nums;
        
    }

    /* Method to print vector. */
    void print(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */

int main()
{
    vector<int> arr = {1, 2, 3, 4};

    Solution s;
    vector<int> ans = s.runningSum(arr);
    s.print(ans);
}