#include <bits/stdc++.h>
using namespace std;

// Time Complexity:- O(n)
// Space Complexity:- O(n)

void print1toN(int n)
{
    // Base Case
    if (n <= 0)
    {
        return;
    }

    // Recursive Case
    // first we go to base case and while comming back from the base case we print the value of n.
    print1toN(n - 1);

    // Backtracking step.
    cout << n << endl;
}

int main()
{
    int n = 10;
    print1toN(n);
}