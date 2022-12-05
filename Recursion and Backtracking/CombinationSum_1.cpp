#include <bits/stdc++.h>
using namespace std;

void solve(int i, int n, int target, vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans)
{
    // base cases
    if (target < 0)
        return;
    if (i >= n)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        else
            return;
    }

    // picking up the ith element
    ds.push_back(arr[i]);
    target -= arr[i];
    solve(i, n, target, ds, arr, ans);
    target += arr[i];
    ds.pop_back();

    // ignoring the ith element
    solve(i + 1, n, target, ds, arr, ans);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;

    solve(0, candidates.size(), target, ds, candidates, ans);
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;
    vector<int> ds;

    vector<vector<int>> ans = combinationSum(arr, target);

    for (auto row : ans)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}