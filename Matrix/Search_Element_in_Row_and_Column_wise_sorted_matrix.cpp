#include <bits/stdc++.h>
using namespace std;

/* Approach 1 Brute force :- Traverse the entire matrix. TC:-O(n^2), SC:- O(1) */

/* Approach 2 Binary Search :- apply binary search on each row.. TC:-O(n log(n)), SC:- O(1) */
bool binarySearch(vector<int> arr, int target)
{
    int s = 0, e = arr.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return false;
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (auto row : matrix)
    {
        if (binarySearch(row, target))
        {
            return true;
        }
    }

    return false;
}

/* Optimized Approach:- Staircase search. TC:-O(n), SC:- O(1) */
bool searchMatrix_Optimized(vector<vector<int>> &matrix, int target)
{
    int i = 0, j = matrix[0].size() - 1;
    // int target = 3;

    while (i < matrix.size() and j >= 0)
    {

        int currentElement = matrix[i][j];
        if (currentElement == target)
        {
            // cout<<i<<","<<j<<endl;
            return true;
        }
        else if (currentElement > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60},
    };
    int target = 3;

    cout<<searchMatrix_Optimized(matrix, target);
}