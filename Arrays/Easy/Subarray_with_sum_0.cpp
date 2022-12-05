#include <bits/stdc++.h>
using namespace std;

/* Approach 1:- Brute Force, Consider all subarrays and check if any subarray exist with sum equal to 0. TC:- O(n^2), SC:- O(1). */
bool subArrayExists(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (sum == 0)
            {
                return true;
            }
        }
    }
    return false;
}

/* Approach 2:- Optimized, TC:- O(n), SC:- O(n). */
/*
The idea is to iterate through the array and for every element arr[i], calculate the sum of elements from 0 to i (this can simply be done as sum += arr[i]). If the current sum has been seen before, then there is a zero-sum array.
*/
bool subArrayExists_Optimized(int arr[], int n)
{
    int sum = 0;
    int f = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0 or m[sum] or arr[i] == 0)
        {
            f = 1;
            break;
        }
        else
        {
            m[sum] = 1;
        }
    }
    if (f == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // bool ans = subArrayExists(arr, n);
    bool ans = subArrayExists_Optimized(arr, n);
    if (ans)
    {
        cout << "Subarray Exist's with sum equal to 0.\n";
    }
    else
    {
        cout << "There is no Subarray Exist's with sum equal to 0.\n";
    }
}