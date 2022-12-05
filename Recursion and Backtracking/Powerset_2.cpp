#include <bits/stdc++.h>
using namespace std;

// Time Complexity:- O(2^n)
// Space Complexity:- O(n)
void generatePowerSet(int i, int n, vector<int> &arr, vector<int> &subset, vector<vector<int>> &powerset)
{
    // Base Case
    if (i >= n)
    {
        powerset.push_back(subset);
        return;
    }

    // Recursive Case
    // picking the ith element
    subset.push_back(arr[i]);

    generatePowerSet(i + 1, n, arr, subset, powerset);

    subset.pop_back();

    // ignoring the ith element
    while (i+1 < n && arr[i+1] == arr[i])
    {
        i++;
    }
    
    generatePowerSet(i + 1, n, arr, subset, powerset);
}

int main()
{
    // duplicate elements
    vector<int> arr = {1, 2, 2};

    
    // sort the array first and give it to generate subset function.
    // sort(arr.begin(), arr.end());
    vector<int> subset;
    vector<vector<int>> powerset;
    generatePowerSet(0, arr.size(), arr, subset, powerset);

    for(auto row:powerset){
        for(auto col:row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
}