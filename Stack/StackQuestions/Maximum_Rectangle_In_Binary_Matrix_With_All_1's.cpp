/*
Question:- Given a binary Matrix M of size m*n. Find the maximum area of rectangle formed by only 1's in the given matrix.

Ex:- n = m = 4;

M[4][4] = {
    {0,1,1,0},
    {1,1,1,1},
    {1,1,1,1},
    {1,1,0,0},
};

Answer:- size of maximum rectangle with all 1's is 8.
the maximum size rectangle is form M[1][0] to M[2][3], i.e.,
                                                                1 1 1 1
                                                                1 1 1 1
*/


// Time Complexity:- O(n*m)
// Space Complexity:- O(m)

#include <bits/stdc++.h>
using namespace std;

// Next Smaller element
vector<int> nextSmallerElement(vector<int> &arr)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(arr.size(), 0);

    for (int i = arr.size() - 1; i >= 0; i--)
    {

        while (s.top() != -1 && arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}


// Previous Smaller element
vector<int> prevSmallerElement(vector<int> &arr)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(arr.size(), 0);

    for (int i = 0; i < arr.size(); i++)
    {
        while (s.top() != -1 && arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}


int largest_rectangle_in_Histogram_using_Stack(vector<int> &heights)
{

    int n = heights.size();

    // storing index of next smaller element for all elements.
    vector<int> next(n);
    next = nextSmallerElement(heights);
    // storing index of previous smaller element for all elements.
    vector<int> prev(n);
    prev = prevSmallerElement(heights);

    int maxArea = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int length = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }

        int breadth = next[i] - prev[i] - 1;
        int area = length * breadth;
        maxArea = max(maxArea, area);
        // cout << "Area of " << heights[i] << " = " << area << endl;
    }

    return maxArea;
}
int maxArea(vector<vector<int>> &M, int row, int col)
{
    // compting the area of 1st row.
    int area = largest_rectangle_in_Histogram_using_Stack(M[0]);
    // cout<<area;
    
    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // update row by adding vlaues of previous row
            if(M[i][j] != 0){
                M[i][j] += M[i-1][j];
            }
            else{
                M[i][j] = 0;
            }
        }
        
        area = max(area, largest_rectangle_in_Histogram_using_Stack(M[i]));
    }
    
    return area;
}

int main()
{
    vector<vector<int>> M = {
        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,0},
    };

    int row = M.size();
    int col = M[0].size();
    cout<< maxArea(M, row, col);
}