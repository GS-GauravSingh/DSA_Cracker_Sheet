#include <bits/stdc++.h>
#include "../Binary Tree Implementation/Binary_Tree_Implementation.h"
using namespace std;

/*
Time complexity:- O(N).
Space Complexity:- O(N)
*/
int checkMirrorTree(int n, int e, int A[], int B[])
{
    unordered_map<int, stack<int>> m;

    for (int i = 0; i < 2 * e; i += 2)
    {
        m[A[i]].push(A[i + 1]);
    }

    for (int i = 0; i < 2 * e; i += 2)
    {
        if (m[B[i]].top() != B[i + 1])
        {
            return 0;
        }
        m[B[i]].pop();
    }
    return 1;
}

int main()
{
    int A[] = {1, 2, 1, 3};
    int B[] = {1, 3, 1, 2};

    int e = 2; // number of edges.
    int n = 3;

    cout << checkMirrorTree(n, e, A, B);
}