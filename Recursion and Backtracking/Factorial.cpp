#include <bits/stdc++.h>
using namespace std;

// Time Complexity:- O(n)
// Space Complexity:- O(n)
int factorial(int n)
{
    // Base Case
    if (n == 0)
    {
        return 1;
    }

    // Recursive Case
    return n * factorial(n - 1);
}

int main()
{
    int n = 5;
    cout << factorial(n);
}