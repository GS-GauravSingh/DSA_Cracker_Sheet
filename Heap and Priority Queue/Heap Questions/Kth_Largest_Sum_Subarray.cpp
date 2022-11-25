#include <bits/stdc++.h>
using namespace std;

/*
Approach 1:- store the sum of all subarrays into vector and return kth element from back side of vector.

Time Complexity:- O(n^2 log(n))
Space Complexity:- O(n^2)
*/
int getKthLargest_BruteForce(vector<int> arr, int k)
{
    vector<int> sumOfKSubarrays;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            sumOfKSubarrays.push_back(sum);
        }
    }

    sort(sumOfKSubarrays.begin(), sumOfKSubarrays.end());

    return sumOfKSubarrays[sumOfKSubarrays.size() - k];
}


/*
Approach 2:- code using min heap.

Time Complexity:- O(n^2 log(n))
Space Complexity:- O(k)
*/
int getKthLargest_Optimized(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> mini;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (mini.size() < k)
            {
                mini.push(sum);
            }
            else
            {
                if (sum > mini.top())
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    int k = 2;
    cout << getKthLargest_BruteForce(arr, k)<<endl;
    cout << getKthLargest_Optimized(arr, k)<<endl;
}