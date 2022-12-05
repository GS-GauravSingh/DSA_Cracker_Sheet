#include <bits/stdc++.h>
using namespace std;

/* Approach:- Hashing. TC:- O(n), SC:- O(n) */
void moreThanNbyk(int *arr, int n, int k)
{
    int occur = n / k;

    // count the frequency of each element and storing in map.
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // Traverse the map and print the element which has frequency more than n/k.
    for (auto i : freq)
    {
        if (i.second > occur)
        {
            cout << i.first << endl;
        }
    }
}

int main()
{
    int arr[] = { 1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 }, k = 4, n = sizeof(arr) / sizeof(arr[0]);

    moreThanNbyk(arr, n, k);
}