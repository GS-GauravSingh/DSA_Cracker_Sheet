#include <bits/stdc++.h>
using namespace std;

// Time Complexity:- O(n)
// Space Complexity:- O(1)
int minJumps(int arr[], int n)
{

    // Base Case
    if (n <= 1)
        return 0;

    // if arr[0] == 0, means it is not possible to jump. Return -1.
    if (arr[0] == 0)
        return -1;

    // initialization
    // stores the maximum index that you can reach from here.
    int maxReach = arr[0];

    // stores the number of steps we can take from here.
    int step = arr[0];

    // stores the number of jumps
    int jump = 1;

    
    for (int i = 1; i < n; i++)
    {
        // if we reached the end of the array, return jump.
        if (i == n - 1)
            return jump;

        // updating maxReach
        maxReach = max(maxReach, i + arr[i]);

        // we use a step to get to the current index, so decrement the step.
        step--;

        // If step == 0, means we took a jump. So increment jump.
        if (step == 0)
        {
            jump++;

            // Check if the current index/position or lesser index
            // is the maximum reach point from the previous indexes
            if (i >= maxReach)
                return -1;

            // re-initialize the steps to the amount
            // of steps to reach maxReach from position i.
            step = maxReach - i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = 11;

    cout << minJumps(arr, n);
}