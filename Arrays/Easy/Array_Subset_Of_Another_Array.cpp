#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> M;
    int c = 0;
    for (int i = 0; i < m; i++)
    {
        M[a2[i]]++;
        c++;
    }

    for (int j = 0; j < n; j++)
    {
        if (M.find(a1[j]) != M.end())
            c--;
    }
    if (c == 0)
        return "Yes";
    else
        return "No";
}

int main()
{
    int a1[] = {11, 1, 13, 21, 3, 7};
    int a2[] = {11, 3, 7, 1};

    int n1 = sizeof(a1) / sizeof(a1[0]);
    int n2 = sizeof(a2) / sizeof(a2[0]);

    cout << isSubset(a1, a2, n1, n2);
}