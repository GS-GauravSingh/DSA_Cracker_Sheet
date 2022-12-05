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
    generatePowerSet(i + 1, n, arr, subset, powerset);
}

int main()
{
    // all unique elements.
    vector<int> arr = {1, 2, 3};

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