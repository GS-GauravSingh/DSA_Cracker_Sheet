#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/

class Solution
{
    /* Recursive Approach */
    // Time Complexity:- O(2^n)
    // Space Complexity:- O(n)
    int fibonacciRecursive(int n)
    {
        // Base Case
        if (n == 0 || n == 1)
        {
            return n;
        }

        return fib(n - 1) + fib(n - 2);
    }

    /* Iterative Approach */
    // Time Complexity:- O(n)
    // Space Complexity:- O(1)
    int fibonacciIterative(int n)
    {
        // Base Case
        if (n == 0 || n == 1)
        {
            return n;
        }

        int num1 = 0;
        int num2 = 1;
        int num3;
        for (int i = 2; i <= n; i++)
        {
            num3 = num1 + num2;
            num1 = num2;
            num2 = num3;
        }

        return num3;
    }

public:
    int fib(int n)
    {
        // Base Case
        if (n == 0 || n == 1)
        {
            return n;
        }

        // return fibonacciRecursive(n);
        return fibonacciIterative(n);
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */


int main()
{
    int n = 5;

    Solution s;
    cout<<s.fib(n);
}