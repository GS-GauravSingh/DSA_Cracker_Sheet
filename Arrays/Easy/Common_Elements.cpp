#include <bits/stdc++.h>
using namespace std;

// Approach:- hashing, TC:- O(n1 + n2 + n3), SC:- O(n1 + n2 + n3)
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    unordered_map<int, int> m1, m2, m3;
    for (int i = 0; i < n1; i++)
        m1[A[i]]++;

    for (int j = 0; j < n2; j++)
        m2[B[j]]++;

    for (int k = 0; k < n3; k++)
        m3[C[k]]++;

    vector<int> ans;

    for (int i = 0; i < n1; i++)
    {
        if (m1[A[i]] and m2[A[i]] and m3[A[i]])
        {
            ans.push_back(A[i]);
            m1[A[i]] = 0;
        }
    }
    return ans;
}

int main()
{
    int n1 = 6, A[] = {1, 5, 10, 20, 40, 80};
    int n2 = 5, B[] = {6, 7, 20, 80, 100};
    int n3 = 8, C[] = {3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> ans = commonElements(A, B, C, n1, n2, n3);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}