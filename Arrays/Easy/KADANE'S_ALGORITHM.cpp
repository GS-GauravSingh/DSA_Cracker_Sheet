#include <bits/stdc++.h>
using namespace std;

// arr: input array
// n: size of array
// Function to find the sum of contiguous subarray with maximum sum.
long long maxSubarraySum_1(int arr[], int n)
{
    int currentSum = 0;
    int maxSum = 0;

    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];

        if (currentSum < 0)
        {
            currentSum = 0;
        }
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

// if a testcase contains all negative elements then the above code is not work as expected. Use the below code this will work on all the testcases.
long long maxSubarraySum_2(int arr[], int n)
{

    // Your code here
    int currentSum = arr[0];
    int maxSum = arr[0];

    for (int i = 1; i < n; i++)
    {
        currentSum += arr[i];

        if (currentSum < arr[i])
        {
            currentSum = arr[i];
        }
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main()
{
    int arr[] = {1, 2, 3, -2, 5};
    int n = 5;

    cout << maxSubarraySum_2(arr, n);
}