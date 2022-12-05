#include <bits/stdc++.h>
using namespace std;

// Note:- Order does not matter here.

/* Brute Force Approach:- Using Extra space. TC:- O(n), SC:- O(n) */
void moveNegative(vector<int> &arr)
{
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        // first push all negative elements.
        if (arr[i] < 0)
        {
            ans.push_back(arr[i]);
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        // then push all non-negative elements.
        if (arr[i] >= 0)
        {
            ans.push_back(arr[i]);
        }
    }

    // update answer
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = ans[i];
    }
}

/* Optimized Approach:- Using 2 pointer. TC:- O(n), SC:- O(1) */
void moveNegative_Optimized(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    while (low < high)
    {
        if (arr[low] < 0)
        {
            low++;
        }
        else if (arr[high] > 0)
        {
            high--;
        }
        else
        {
            swap(arr[low], arr[high]);
        }
    }
}

/* Method to print vector. */
void printVec(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};

    moveNegative_Optimized(arr);
    printVec(arr);
}