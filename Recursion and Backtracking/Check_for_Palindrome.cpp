#include <bits/stdc++.h>
using namespace std;


/* Recursive Function to check if string is palindrome or not. TC:- O(n), SC:- O(n) */
bool check(string str, int start, int end)
{
    // Base Case
    if(start >= end){
        return true;
    }
    if(str[start] != str[end]){
        return false;
    }

    // Recursive Case
    return check(str, start+1, end-1);
}


int main()
{
    string str = "madam";
    cout<<check(str, 0, str.length()-1);
}