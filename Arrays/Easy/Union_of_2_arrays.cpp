#include <bits/stdc++.h>
using namespace std;

/* Approach:- Using set. TC:- O((n+m)log(n+m)), SC:- O(n+m) */

// Function to return the count of number of elements in union of two arrays.
int doUnion(int a[], int n, int b[], int m)
{
    set<int> s;

    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    for (int i = 0; i < m; i++)
        s.insert(b[i]);

    int count = s.size();
    return count;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3};

    cout << doUnion(a, 5, b, 3);
}