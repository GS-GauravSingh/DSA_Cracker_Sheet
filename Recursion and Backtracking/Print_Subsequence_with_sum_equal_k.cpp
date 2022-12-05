#include <bits/stdc++.h>
using namespace std;

/* Method to print vector. */
void printVec(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* Recursive Function to Print all subsequences. TC:- O(2^n), SC:- O(n) */
void printSubsequence(vector<int> &arr, vector<int> &ds, int i, int k, int sum)
{
    // Base Case
    if (i >= arr.size())
    {
        if (sum == k)
        {
            printVec(ds);
        }
        return;
    }


    // Recursive Case
    // taking the ith element.
    ds.push_back(arr[i]);
    sum += arr[i];

    printSubsequence(arr, ds, i + 1, k, sum);

    // Backtracking Step.
    sum -= arr[i];
    ds.pop_back(); 

    // ignoring the ith element.
    printSubsequence(arr, ds, i + 1, k, sum);
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int k = 2;
    vector<int> ds;
    printSubsequence(arr, ds, 0, k, 0);
}