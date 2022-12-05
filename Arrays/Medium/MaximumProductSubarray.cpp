#include <bits/stdc++.h>
using namespace std;

// Function to find maximum product subarray
/* Approach 1:- Brut Force, TC:- O(n^3), SC:- O(1). */
long long maxProduct(vector<int> &arr, int n)
{
    long long maxP = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            long long product = 1;
            for (int k = i; k <= j; k++)
            {
                product *= arr[k];
            }
            maxP = max(maxP, product);
        }
    }
    return maxP;
}

/* Approach 1:- Optimized, TC:- O(n), SC:- O(1). */
long long maxProduct(vector<long long> &arr, int n)
{
    // Variables to store maximum and minimum
    // product till ith index.
    long long minVal = arr[0];
    long long maxVal = arr[0];

    long long maxProduct = arr[0];

    for (int i = 1; i < n; i++)
    {

        // When multiplied by -ve number,
        // maxVal becomes minVal
        // and minVal becomes maxVal.
        if (arr[i] < 0)
            swap(maxVal, minVal);

        // maxVal and minVal stores the
        // product of subarray ending at arr[i].
        maxVal = max(arr[i], maxVal * arr[i]);
        minVal = min(arr[i], minVal * arr[i]);

        // Max Product of array.
        maxProduct = max(maxProduct, maxVal);
    }

    // Return maximum product found in array.
    return maxProduct;
}

int main()
{
    vector<int> arr = {6, -3, -10, 0, 2};

    cout << maxProduct(arr, arr.size());
}