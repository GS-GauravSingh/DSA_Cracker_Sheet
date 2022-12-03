#include <bits/stdc++.h>
using namespace std;

// Time Complexity:- O(m+n), m and n are sizes of vector.
// Space Complexity:- O(1).

/* Additional function to print vector. */
void printVec(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* Function to merge 2 sorted arrays. TC:- O(m+n), SC:- O(1)  */
vector<int> merge2SortedArrays(vector<int> arr1, vector<int> arr2)
{
    vector<int> ans;

    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            ans.push_back(arr2[j]);
            j++;
        }
    }

    // copy remaining elements.
    while (i < arr1.size())
    {
        ans.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size())
    {

        ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

/* Function to find median element. TC:- O(1), SC:- O(1) */
int find_median(vector<int> arr)
{

    int median = -1;
    int size = arr.size();

    if (size & 1)
    {
        // odd length
        median = arr[size / 2];
    }
    else
    {
        // even length
        median = (arr[size / 2] + arr[(size / 2) - 1]) / 2;
    }
    return median;
}

/* Function to find median of 2 sorted array of equal size. */
int medianOf2SortedArrays(vector<int> arr1, vector<int> arr2)
{
    // step1 1:- merge 2 sorted arrays.
    vector<int> merge = merge2SortedArrays(arr1, arr2);
    printVec(merge);

    // step 2:- find median.
    int median = find_median(merge);

    return median;
}

int main(void)
{
    vector<int> arr1 = {1, 5, 9};
    vector<int> arr2 = {2, 3, 6, 7};


    cout << "Median Element is " << medianOf2SortedArrays(arr1, arr2);
}