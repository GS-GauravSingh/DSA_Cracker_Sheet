#include <bits/stdc++.h>
using namespace std;


/* Recursive Function to Reverse array. TC:- O(n), SC:- O(n) */
void reverseRecursive(vector<int> &arr, int start, int end)
{
    // Base Case
    if(start >= end){
        return;
    }

    // Recursive Case
    swap(arr[start], arr[end]);
    reverseRecursive(arr, start+1, end-1);
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
    vector<int> arr = {1, 2, 3, 4, 5};

    cout<<"Before:- ";
    printVec(arr);

    cout<<"After:- ";
    reverseRecursive(arr, 0, arr.size()-1);
    printVec(arr);
}