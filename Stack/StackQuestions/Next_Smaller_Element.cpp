/*

Ques:- given an array of length n, your task is to find the next smaller for each element of the array.

Next Smaller Element is the first smaller element to right of that element.

Example:- arr:- {2,1,4,3}
for 2:- the first smaller elemnt from the right is 1,
for 1:- for 1 there is no smaller element present at right in that case ans in -1,
for 4:- the first smaller element to the right is 3,
for 3:- there is no element to the right.So, the answer is -1.

*/

#include <bits/stdc++.h>
#include "../Stack Implementations/Stack_Implementation_Using_Vector.h"
using namespace std;

//------------- Brute Force Approach --------------------------------

// Time Complexity:- O(n^2)
// Space Complexity:- O(1)

// function to print vector
void printVec(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// function to find next smaller element
vector<int> nextSmallerElement(vector<int> &arr)
{
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        // variable to check if we found next smaller element for arr[i].
        bool found = false;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                // whenever we found the first element which is smaller than arr[i], we push that element is answer and return for here.
                found = true;
                ans.push_back(arr[j]);
                break;
            }
        }

        // if we cannot find any smaller element than push -1 in our ans vector.
        if (found != true)
        {
            ans.push_back(-1);
        }
    }

    return ans;
}

//--------------------- Optimized Approach using Stack ------------------------

// Time Complexity:- O(n)
// Space Complexity:- O(n)
vector<int> nextSmallerElementUsingStack(vector<int> &arr)
{
    Stack<int> s;
    // push -1 into stack, because we traverse from right,
    // and we know for the right most element the next smaller element is -1.
    s.push(-1);

    // ans vector
    vector<int> ans(arr.size(), 0);

    // traverse from right
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        // if s.top() < arr[i], push s.top() in ans vector.
        // and push arr[i] into stack.
        
        // else if s.top() > arr[i], then iterate through the whole stack and find if there is any element which is less than arr[i], if yes then our loop terminates at that element, else out loop terminates at -1, because initially we push -1 into stack.
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(arr[i]);
        
    }

    return ans;
}

int main(void)
{
}