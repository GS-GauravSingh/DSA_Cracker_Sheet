#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    /* Brute Force Approach:- Using nested loops. */
    // Time Complexity:- O(n^2)
    // Space Complexity:- O(1)
    int maxArea_BruteForce(vector<int> &heights)
    {
        int maxArea = INT_MIN;
        for (int i = 0; i < heights.size() - 1; i++)
        {
            for (int j = i + 1; j < heights.size(); j++)
            {
                int width = j - i;
                int height = min(heights[i], heights[j]);
                int area = width * height;
                maxArea = max(area, maxArea);
            }
        }

        return maxArea;
    }

    /* Optimized Approach:- Using 2 pointer. */
    // Time Complexity:- O(n)
    // Space Complexity:- O(1)
    int maxArea_Optimized(vector<int> &heights)
    {
        int left = 0;
        int right = heights.size()-1;
        int maxArea = INT_MIN;

        while (left < right)
        {
            int leftHeight = heights[left];
            int rightHeight = heights[right];
            int mimimumHeight = min(leftHeight, rightHeight);

            // calculating area.
            int height = mimimumHeight;
            int width = right - left;
            int area = height*width;
            maxArea = max(area, maxArea);

            // move pointers.
            if(leftHeight < rightHeight){
                left++;
            }
            else{
                right--;
            }

        }
        return maxArea;
        
        
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution s;
    cout << s.maxArea_BruteForce(height) << endl;
    cout << s.maxArea_Optimized(height) << endl;
}