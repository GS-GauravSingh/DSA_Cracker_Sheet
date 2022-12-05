#include <bits/stdc++.h>
using namespace std;

// Time Complexity:- O(2^n)
// Space Complexity:- O(n)
int fib(int n)
{
    // Base Case
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{
    int n = 5;
    cout << fib(n);
}