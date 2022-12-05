#include <bits/stdc++.h>
using namespace std;

// Note:- order matters here.

/* Approach 1:- using extra space, TC:- O(n), SC:- (n). */
void rearrange(int *arr, int n)
{
    // push +ve and -ve elements in seperate arrays.
    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }

    // traverse the original array and store elements in desired format.
    int i = 0, j = 0, k = 0;
    while (i < pos.size() && j < neg.size())
    {
        // first push -ve element then +ve element.
        arr[k++] = neg[i++];
        arr[k++] = pos[j++];
    }

    // push remaining elements.
    while (i < neg.size())
    {
        arr[k++] = neg[i++];
    }

    while (j < pos.size())
    {
        arr[k++] = pos[j++];
    }
}

/* Approach 2:- using 3 pointer, TC:- O(n^2), SC:- (1). */
void rotate(int *arr, int start, int end)
{
    int temp = arr[end];
    for (int i = end - 1; i >= start; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[start] = temp;
}

void rearrange_Optimized(int *arr, int n)
{
    // -ve elements = even index.
    // +ve elements = odd index.

    int i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n)
    {
        // traverse the array using k.

        // Even index must have -ve number.
        if (k % 2 == 0)
        {
            // check if +ve elements is present.
            if (arr[k] >= 0)
            {
                // if +ve number is present at even index.
                // find the first -ve number and swap it, using i and j pointer.

                i = j = k;
                while (i < n && arr[i] >= 0)
                    i++;
                // if no -ve element is present.
                if (i >= n)
                {
                    break;
                }

                // shift elements.
                rotate(arr, j, i);
            }
        }

        // odd index must have +ve number.
        else
        {
            // check if -ve elements is present.
            if (arr[k] < 0)
            {
                // if -ve number is present at odd index.
                // find the first +ve number and swap it, using i and j pointer.
                i = j = k;
                while (j < n && arr[j] < 0)
                    j++;
                // if no -ve element is present.
                if (j >= n)
                {
                    break;
                }

                // shift elements.
                rotate(arr, i, j);
            }
        }
        k++;
    }
}

int main()
{
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrange_Optimized(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}