#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    /* Brute Force Approach. */
    // Time Complexity:- O(m+n log(m+n)), m and n are size of vectors.
    // Space Complexity:- O(log(n)) recursive stack space for sorting. 
    void mergeBruteForce(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[i + m] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }

    /* Optimized Approach. */
    // Time Complexity:- O(n), n is size of nums2.
    // Space Complexity:- O(1)
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1; // variable to traverse both vectors.
        int k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] < nums2[j])
            {
                // we are inserting elements from back. 
                // So we have to insert elements in descending order.
                nums1[k--] = nums2[j--];
            }
            else{
                nums1[k--] = nums1[i--];

            }
        }

        // if nums2 has some elements left.
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }

    /* Method to print vector. */
    void print(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */

int main()
{
    vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    vector<int> arr2 = {2, 5, 6};
    int m = 3;
    int n = 3;

    Solution s;
    s.merge(arr1, m, arr2, n);
    s.print(arr1);
}