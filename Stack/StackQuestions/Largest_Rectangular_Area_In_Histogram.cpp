/*
Question :- give an array of integers, representing the height of rectangles, where width of each rectangle is 1. Your task is to return the area of largest rectangle.

----------------------------- Brute Force approach -----------------------
solution:- Area = length * breadth.
So, in order to return the area of largest rectangle we havo to maximize the breadth.
In order to maximize the breadth, iterate to the left and right from the current element and check if we can extend the width of current element.

We can only extend the width if all the elements present at left or right is greater than or equal to the current element.

Ex:- heights = {2,1,5,6,2,3};
Solution:- we know that width of each rectangle is 1.

for 2:- there is no elements present at left, so we cannot extend the width of 2 in left side and we cannot extend the width of 2 in right size because the element present at right is 1 which is smaller than 2. So, area of 2 = height * width. area of 2 = 2 * 1 = 2.

Area of 2 = 2;

for 1:- we can extend the width of current element i.e., 1 in left side because element present at right is greater that 1. So, now width becomes 2 [width of 2 is 1, 1+1 = 2]. Nodw from left our width is 1.

in case of right we can extend the width of 1 till we reach to last element 3 because all the elements are greater than 1.
Now width from right becomes 4.

Area for 1 = height of 1 * width of 1;
Area = 1 * 5 + 1; [width = width from left + width from right .i.,e 4+1 = 5, +1 is for adding the width for current element].

Area of 1 = 6;

and that's how you can calculate the area of largest rectangle.

// Time complexity:- O(n^2)
// Space complexity:- O(1)

--------------------------Brute force approach end here. ---------------------------------

Optimized Approach :- using stack.

for each element store the indexes of next smaller element and previous smaller element.

width = n * p - 1; , n = index of next smaller element, p = index of prev smaller element.
and length is constant, now you can easily find area.

// Time complexity:- O(n)
// Space complexity:- O(n)

*/

#include <bits/stdc++.h>
using namespace std;

//------------------ Brute Force -----------------------------

// Time complexity:- O(n^2)
// Space complexity:- O(1)
int largest_rectangle_in_Histogram(vector<int> &heights)
{
    // Base Case
    if (heights.size() == 1)
    {
        return heights[0];
    }

    int maxArea = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        int area = 0;
        // width = 1, because we are including the width of current element we are standing on.
        int width = 1;
        // checking if we can extend the area of current element to left.
        int j = i - 1;
        while (j >= 0 && heights[j] >= heights[i])
        {
            width++;
            j--;
        }

        // checking if we can extend the area of current element to right.
        j = i + 1;
        while (j < heights.size() && heights[j] >= heights[i])
        {
            width++;
            j++;
        }

        // calculating area
        area = heights[i] * width;
        maxArea = max(area, maxArea);
        cout << "Area of " << heights[i] << " = " << area << endl;
    }

    return maxArea;
}
//------------------ Brute Force ends Here. -----------------------------

//------------------ Optimized Approach -----------------------------

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
        cout << "Area of " << heights[i] << " = " << area << endl;
    }

    return maxArea;
}
//------------------ Optimized approach ends Here.-------------------

int main()
{
    vector<int> heights = {1, 1};
    // cout<<largest_rectangle_in_Histogram(heights);

    cout << largest_rectangle_in_Histogram_using_Stack(heights);
}