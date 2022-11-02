
/*
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

Example 1:

Input:- N = 5, A[] = {-8, 2, 3, -6, 10}, K = 2
Output:-  -8 0 -6 -6

Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

Approach:- Using Doubly Ended Queue.

Step 1:- Insert 1 K elements and find first -ve integer in this window.
Step 2:- when we are going to next window, ek element pop hoga or ek element push hoga.
Ex:- first window :- {-8, 2} = -8 (first -ve integer).
Next window me, -8 pop ho gya and 3 push ho gya, {2, 3} = 0 (does not contain a negative integer).

Jais Jaise hum next window me jayenge ek element add of dequeue me back se (push_back()) and ek element remove hoga front se (pop_front()).

*/

#include <bits/stdc++.h>
using namespace std;

/* Function to find first -ve integer in window of K */
vector<long long> printFirstNegativeInteger(long long int arr[], long long int N, long long int K)
{
    deque<long long int> dq;
    vector<long long int> ans;

    // Process 1st window of size k
    for (int i = 0; i < K; i++)
    {
        // pusn only index of negative elements, there is no need of +ve elements.
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // store answer of first k sized window, because we only push -ve element in dequeue.
    // So, our ans is present at front of dequeue (because we need first -ve  integer).
    if (dq.size() > 0)
    {
        // if dequeue size is not 0, it means, some -ve elements are present in window of size k.
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        // if dequeu is empty it means ther is no -ve elements in window of size k.
        // if there is no-ve element in window of size k, then the answer is 0.
        ans.push_back(0);
    }

    // Process all remaining windows.
    // i = k, because we already process 1st window of size k.
    for (int i = K; i < N; i++)
    {
        // while going to the next window remove the front element and push the next element.
        if (!dq.empty() && i - dq.front() >= K)
        {
            // element present at dq.front(), is not the part of current window.
            dq.pop_front();
        }

        // Addition of next element
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }

        // Store answer
        if (dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}

/* Function to print array */
void print(vector<long long> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    long long int arr[] = {-8, 2, 3, -6, 10};
    long long int size = sizeof(arr) / sizeof(arr[0]);
    vector<long long> ans;

    int k = 2;
    ans = printFirstNegativeInteger(arr, size, k);
    print(ans);
}