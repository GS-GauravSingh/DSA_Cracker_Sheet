#include <bits/stdc++.h>
using namespace std;

/* Brute Force Approach:- Funtion to Sort the array of 0,1,2. TC:- O(n log(n)), SC:- O(1) */
void sortArray(vector<int> &arr)
{

    // using inbuild sort function.
    sort(arr.begin(), arr.end());
}

/* Optimized Approach:- Using Dutch National Flag Algorithm. TC:- O(n), SC:- O(1) */
void sort012(vector<int> &arr)
{

    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high)
    {
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            // arr[mid] == 2.
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    
}

/* Method to print vector. */
void printVec(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {0, 2, 1, 2, 0};

    // cout<<"Brute Force:- ";
    // sortArray(arr);
    // printVec(arr);

    cout<<"Optimized:- ";
    sort012(arr);
    printVec(arr);
}