#include <bits/stdc++.h>
using namespace std;

int find_median(vector<int> v)
{
    sort(v.begin(), v.end());
    int median = -1;
    int size = v.size();

    if (size & 1)
    {
        // odd length
        median = v[size / 2];
    }
    else
    {
        // even length
        median = (v[size / 2] + v[(size / 2) - 1]) / 2;
    }
    return median;
}

int main(void)
{
    vector<int> arr1 = {56, 67, 30, 79};      // odd length
    vector<int> arr2 = {90, 100, 78, 89, 67}; // even length

    cout<<find_median(arr1)<<endl;
    cout<<find_median(arr2)<<endl;
}