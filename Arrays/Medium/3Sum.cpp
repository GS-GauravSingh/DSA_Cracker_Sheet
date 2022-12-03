#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    // Time Complexity:- O(n^2) + O(n log(n)) => O(n^2), n is the size of vector.
    // Space Complexity:- O(1)
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            int target = -num;

            int start = i + 1;
            int end = n - 1;
            while (start < end)
            {
                int sum = nums[start] + nums[end];
                if (sum == target)
                {
                    ans.push_back({nums[i], nums[start], nums[end]});

                    // skipping duplicate elements
                    while (start < end && nums[start] == nums[start + 1])
                    {
                        start++;
                    }
                    while (start < end && nums[end] == nums[end - 1])
                    {
                        end--;
                    }

                    start++;
                    end--;
                }
                else if (sum > target)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }

            // skipping duplicate elements
            while (i + 1 < n && nums[i] == nums[i + 1])
            {
                i++;
            }
        }

        return ans;
    }

    /* Method to print 2D vector. */
    void print(vector<vector<int>> arr)
    {

        for (int i = 0; i < arr.size(); i++)
        {
            int col = arr[i].size();
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */
int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -1};

    Solution s;
    vector<vector<int>> ans = s.threeSum(arr);
    s.print(ans);
}