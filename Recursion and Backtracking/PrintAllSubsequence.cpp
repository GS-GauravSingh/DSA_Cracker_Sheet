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
void printSubsequence(vector<int> &arr, vector<int> &ds, int i)
{
    // Base Case
    if (i >= arr.size())
    {
        printVec(ds);
        return;
    }

    // Recursive Case
    // taking the ith element.
    ds.push_back(arr[i]);
    printSubsequence(arr, ds, i + 1);
    ds.pop_back(); // Backtracking Step.

    // ignoring the ith element.
    printSubsequence(arr, ds, i + 1);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> ds;
    printSubsequence(arr, ds, 0);
}