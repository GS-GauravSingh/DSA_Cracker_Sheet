#include <bits/stdc++.h>
using namespace std;

// Time Complexity:- O(n)
// Space Complexity:- O(n)

void printNto1(int n)
{
    // Base Case
    if (n <= 0)
    {
        return;
    }

    // Recursive Case
    // first we print the value of n and then move towards the base case.
    cout << n << endl;
    printNto1(n - 1);

}

int main()
{
    int n = 10;
    printNto1(n);
}