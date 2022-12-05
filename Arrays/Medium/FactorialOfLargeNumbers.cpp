#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int N)
{
    vector<int> ans;
    ans.push_back(1);
    for (int i = 2; i <= N; i++)
    {
        int carry = 0;
        for (int j = 0; j < ans.size(); j++)
        {
            int value = ans[j] * i + carry;
            ans[j] = value % 10;
            carry = value / 10;
        }
        while (carry)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n = 100;
    vector<int> ans = factorial(n);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}