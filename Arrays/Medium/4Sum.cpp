#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    // Time Complexity:- O(n^3)
    // Space Complexity:- O(1)
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            long long firstElement = nums[i];

            for (int j = i + 1; j < n; j++)
            {
                long long secondElement = nums[j];

                long long start = j + 1;
                long long end = n - 1;

                while (start < end)
                {
                    long long thirdElement = nums[start];
                    long long fourthElement = nums[end];

                    long long sum = firstElement + secondElement + thirdElement + fourthElement;
                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});

                        // remove duplicate elements.
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

                // remove duplicate elements.
                while (j + 1 < n && nums[j] == nums[j + 1])
                {
                    j++;
                }
            }
            // remove duplicate elements.
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
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution s;
    vector<vector<int>> ans = s.fourSum(arr, target);
    s.print(ans);
}