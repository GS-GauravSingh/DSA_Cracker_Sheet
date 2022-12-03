#include <bits/stdc++.h>
using namespace std;

long long int merge(long long int arr[], long long int start, long long int end)
{
    // first half is from start to mid.
    // Second half is from mid+1 to end.
    long long int i = start, mid = start + (end - start) / 2, j = mid + 1;

    long long int invCount = 0;
    vector<long long int> temp;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;

            invCount += (mid - i) + 1;
        }
    }

    // copy remaining elements from first half.
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    // or copy remaining elements from second half.
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    // copy back the elements of temp to original array.
    int k = 0;
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[k++];
    }

    // return inversion count.
    return invCount;
}

long long int mergeSort(long long int arr[], long long int start, long long int end)
{
    long long int invCount = 0;
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        // left part
        invCount += mergeSort(arr, start, mid);

        // right part
        invCount += mergeSort(arr, mid + 1, end);

        // merge both halfs.
        invCount += merge(arr, start, end);
    }

    return invCount;
}

long long int inversionCount(long long arr[], long long N)
{
    long long int invCount = 0;
    long long int start = 0, end = N - 1;
    invCount += mergeSort(arr, start, end);
    return invCount;
}

int main(void)
{
    long long int arr[] = {2, 4, 5, 6, 7};
    long long int n = 5;

    cout << inversionCount(arr, n) << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}