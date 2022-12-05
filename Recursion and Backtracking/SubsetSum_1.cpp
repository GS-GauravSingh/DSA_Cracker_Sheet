#include <bits/stdc++.h>
using namespace std;

/* Return the sum of all subsets. */

// Time Complexity:- O(2^n)
// Space Complexity:- O(n)
void sumOfAllSubsets(int i, int n, int sum, vector<int> &arr, vector<int> &allSubsetsSum)
{
    // Base Case
    if (i >= n)
    {
        allSubsetsSum.push_back(sum);
        return;
    }

    // Recursive Case
    // picking the ith element

    sum += arr[i];
    sumOfAllSubsets(i + 1, n, sum, arr, allSubsetsSum);
    sum -= arr[i];

    // ignoring the ith element
    sumOfAllSubsets(i + 1, n, sum, arr, allSubsetsSum);
}

int main()
{
    vector<int> arr = {1, 2, 3};

    vector<int> allSubsetsSum;
    sumOfAllSubsets(0, arr.size(), 0, arr, allSubsetsSum);

    for (auto i : allSubsetsSum)
    {
        cout << i << " ";
    }
}