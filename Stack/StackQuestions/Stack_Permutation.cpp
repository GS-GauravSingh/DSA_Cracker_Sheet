//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    /*
    Example:-
    A = {1,2,3};
    B = {2,1,3};

    initially stack is empty.
    when i = 0,
    stack(contains elements of array A).
      1

    j=0;
    in this case s.top() != B[j]

    when i = 1,
    stack(contains elements of array A).
      2
      1

    j=0;
    in this case s.top() == B[j], pop the top element till s.top() == B[j];
    so, B[0] = 2, B[1] = 1, so after popping out stack is empty and j = 2;

    when i = 2,
    stack(contains elements of array A).
      3

    j=2;
    in this case s.top() == B[j], pop the top element till s.top() == B[j];
    so, B[2] = 3 so after popping out stack is empty;

    at the end if our stack is empty it means one array is a stack permutation of the other array.
    in this case stack is empty, so return true.

    if stack is not empty, means one array is not a stack permutation of the other array.
    return false.

    */

    // Time Complexity:- O(N)
    // Space Complexity:- O(N)
    int isStackPermutation(int N, vector<int> &A, vector<int> &B)
    {
        stack<int> s;
        int j = 0; // pointer to traverse array B.
        for (int i = 0; i < N; i++)
        {
            // push elements of array A into Stack.
            s.push(A[i]);

            // if s.top() == B[j], pop the top element and increment j.
            while (!s.empty() && s.top() == B[j])
            {
                s.pop();
                j++;
            }
        }

        // At this point, if stack is empty, it means you can array A is a stack permutation of array B.
        // return true.
        if (s.empty())
        {
            return 1;
        }
        // if stack is not empty, return false.
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.isStackPermutation(n, a, b) << endl;
    }

    return 0;
}
// } Driver Code Ends