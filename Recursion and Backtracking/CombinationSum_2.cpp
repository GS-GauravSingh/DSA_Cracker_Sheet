#include <bits/stdc++.h>
using namespace std;

void help(int i, int target, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans)
{

    if (target < 0)
        return;
    if (i == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        return;
    }

    // pick
    temp.push_back(arr[i]);
    target -= arr[i];
    help(i + 1, target, arr, temp, ans);
    target += arr[i];
    temp.pop_back();

    // ignore
    while (i + 1 < arr.size() and arr[i + 1] == arr[i])
        i++;
        
    help(i + 1, target, arr, temp, ans);
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    help(0, target, candidates, temp, ans);
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = combinationSum2(arr, target);

    for (auto row : ans)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}