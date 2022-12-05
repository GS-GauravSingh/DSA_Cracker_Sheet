#include <bits/stdc++.h>
using namespace std;

/* Brute Force Approach:- Take all the elements of arr1 and arr2 in arr3. Then simply sort the arr3. TC:- O(n+m log(n+m)), SC:- O(1) */
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;

    // traverse the arr1 and insert its element in arr3
    while (i < n1)
    {
        arr3[k++] = arr1[i++];
    }

    // now traverse arr2 and insert in arr3
    while (j < n2)
    {
        arr3[k++] = arr2[j++];
    }

    // sort the whole array arr3
    sort(arr3, arr3 + n1 + n2);
}

/* Optimized Approach 1:- TC:- O(M+N), SC:- O(1) */
void mergeArrays_Optimized(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < n1)
    {
        arr3[k++] = arr1[i++];
    }

    while (j < n2)
    {

        arr3[k++] = arr2[j++];
    }
}

/* Function to print array. */
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
    int arr1[] = {1, 3, 4, 5};
    int arr2[] = {2, 6, 7, 8};
    int n = 4;
    int m = 4;

    int arr3[n + m];
    mergeArrays_Optimized(arr1, arr2, n, m, arr3);
    print(arr3, n + m);
}