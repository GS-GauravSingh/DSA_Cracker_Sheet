#include <bits/stdc++.h>
using namespace std;

// Function to return length of longest subsequence of consecutive integers.
int findLongestConseqSubseq(int arr[], int N)
{
    if (N == 1)
        return 1;

    sort(arr, arr + N);

    int len = 1;
    int ans = 0;
    for (int i = 1; i < N; i++)
    {
        // for duplicate elemnets.
        while (arr[i] == arr[i - 1])
            i++;

        // if difference is 1, then increment length.
        if (arr[i] - arr[i - 1] == 1)
            len++;

        // if difference is not 1, then reinitialize length with 1.
        else
        {
            len = 1;
        }

        // calculate max length.
        ans = max(len, ans);
    }
    return ans;
}

int main()
{
    int arr[] = {2, 6, 1, 9, 4, 5, 3}, n = sizeof(arr) / sizeof(arr[0]);

    cout << findLongestConseqSubseq(arr, n);
}