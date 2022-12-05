#include <bits/stdc++.h>
using namespace std;

// Time Complexity:- O(n!)
// Space Complexity:- O(n)
void solve(int i, int n, vector<int> &nums, vector<vector<int>> &ans)
{
    // Base Case
    if (i >= n)
    {
        ans.push_back(nums);
        return;
    }

    // Recursive Case
    for (int j = i; j < n; j++)
    {
        swap(nums[i], nums[j]);
        solve(i + 1, n, nums, ans);
        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    int i = 0;

    solve(i, nums.size(), nums, ans);
    return ans;
}

int main()
{
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    ans = permute(arr);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}