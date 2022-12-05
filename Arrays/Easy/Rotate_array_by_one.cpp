#include <bits/stdc++.h>
using namespace std;

/* Function to rotate array by one. TC:- O(n), SC:- O(1). */
void rotateByOne(int *arr, int n)
{
    // storeing the last element.
    int lastElement = arr[n-1];

    // shift all element to right by 1.
    for (int i = n-1; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = lastElement;
    
}

/* Method to print array. */
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout<<"Before:- ";
    print(arr,n);

    cout<<"After:- ";
    rotateByOne(arr, n);
    print(arr,n);
}