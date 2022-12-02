#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/

class Solution
{
public:
    // Time Complexity:- O(n^2)
    // Space Complexity:- O(1)
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    ans[i].push_back(1);
                }
                else
                {

                    ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
            }
        }

        return ans;
    }

    /* Method to print 2D vector. */
    void print(vector<vector<int>> arr)
    {

        for (int i = 0; i < arr.size(); i++)
        {
            int col = arr[i].size();
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */

int main()
{

    int numRows = 5;

    Solution s;
    vector<vector<int>> ans = s.generate(numRows);
    s.print(ans);
}