#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity:- O(n log(n))
Space Complexity:- O(n)
*/

// Function to return the minimum cost of connecting the ropes.
long long minCost(long long arr[], long long n)
{
    // create min heap.
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    /*
    jab tak min heap ka size > 1 hai, tab tak heap me se 2 minimum element nikalo or unka sum krke cost me add kro or phir sum ko min heap me push krdo.
    */
    long long cost = 0;
    while (pq.size() > 1)
    {
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        long long sum = a + b;

        // update cost.
        cost += sum;

        // push sum into min heap.
        pq.push(sum);
    }

    return cost;
}

int main()
{

    // There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes.

    long long arr[] = {4, 3, 2, 6};
    long long n = 4;

    cout<<minCost(arr,n)<<endl;
}
