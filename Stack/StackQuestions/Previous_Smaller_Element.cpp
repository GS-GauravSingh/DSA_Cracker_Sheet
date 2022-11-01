
#include<bits/stdc++.h>
#include "../Stack Implementations/Stack_Implementation_Using_Vector.h"
using namespace std;

//--------------------- Optimized Approach using Stack ------------------------

// Time Complexity:- O(n)
// Space Complexity:- O(n)
vector<int> prevSmallerElementUsingStack(vector<int> &arr)
{
    Stack<int> s;
    // push -1 into stack, because we traverse from right,
    // and we know for the right most element the next smaller element is -1.
    s.push(-1);

    // ans vector
    vector<int> ans(arr.size(), 0);

    // traverse from right
    for (int i = 0; i < arr.size(); i++)
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

// function to print vector
void printVec(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(void){
    vector<int> arr = {2,1,4,3};

    vector<int> ans = prevSmallerElementUsingStack(arr);
    printVec(ans);
}