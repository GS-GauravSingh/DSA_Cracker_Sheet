#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/

class Solution
{
public:
    // Time Complexity:- O(n^2)
    // Space Complexity:- O(1)
    int threeSumClosest(vector<int> &nums, int target)
    {
        // Step 1:- sort the vector.
        sort(nums.begin(), nums.end());

        int ans = 0;
        int diff = INT_MAX;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int first = nums[i]; // first element.

            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end)
            {
                int second = nums[start]; // second element.
                int third = nums[end]; // third element.

                int sum = first + second + third;

                if(sum == target){
                    return sum;
                }
                else if(abs(sum - target) < diff){
                    diff = abs(sum - target);
                    ans = sum;
                }
                
                // move pointers.
                if(sum < target){
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        return ans;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */
int main()
{
    vector<int> arr = {-1, 2, 1, -4};
    int target = 1;

    Solution s;
    cout << s.threeSumClosest(arr, target);
}