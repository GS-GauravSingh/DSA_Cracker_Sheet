#include <bits/stdc++.h>
using namespace std;
/*
Approach 1:- sort the given array and return the k-1th index.

Time Complexity:- O(n log(n))
Space Complexity:- O(1)
*/
int kthSmallestElement(vector<int> &arr, int k)
{
    // Base Case
    if (arr.size() == 0)
    {
        return -1;
    }
    if (arr.size() == 1)
    {
        return arr[1];
    }

    // sort the given array and return the k-1th index.
    sort(arr.begin(), arr.end());
    int ans = arr[k - 1];

    return ans;
}

/*
Approach 2:- using Heap.

Step 1:- create max heap for first k elements.
Step 2:- for rest of the elements check,
if(element < heap.top()){
    heap.pop();
    heap.push(element);
}
Step 3:- after step 2, our heap will contain the k smallest elements and the element present at heap.top() is the kth smallest element.


Time Complexity:- O(n log(k))
Space Complexity:- O(k)
*/
int kthSmallestElement_Using_Heap(vector<int> &arr, int k)
{
    // Base Case
    if (arr.size() == 0)
    {
        return -1;
    }
    if (arr.size() == 1)
    {
        return arr[1];
    }

    // step 1:- create max heap for first k elements.
    // priority_queue<int, vector<int>, greater<int>> pq; // this is how we can create MIN Heap.
    priority_queue<int> pq; // by default max heap.
    for (int i = 0; i < k; i++)
    {
        // push first k elements into max heap.
        pq.push(arr[i]);
    }

    /*
    Step 2:- for rest of the elements in our vector(from k to n-1) check,
    if(arr[i] < heap.top()){
        heap.pop();
        heap.push(arr[i]);
    }
    */
    for (int i = k; i < arr.size(); i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // Step 3:- after step 2, our heap will contain the k smallest elements and the element present at heap.top() is the kth smallest element.
    int ans = pq.top();
    return ans;
}

int main()
{
    // from the given unsorted array, your task is to return the kth smallest element.
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 4;

    // int ans = kthSmallestElement(arr, k);
    int ans = kthSmallestElement_Using_Heap(arr, k);
    if (ans != -1)
    {
        cout << k << "th smallest element is " << ans << endl;
    }
}