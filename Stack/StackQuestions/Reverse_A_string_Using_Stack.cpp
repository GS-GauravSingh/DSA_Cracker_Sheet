/*
Note:- Whatever you push into stack, it came out in a reverse order.

Time Complexity:- O(n)
Space Complexity:- O(n), because we're using stack.
*/

#include<bits/stdc++.h>
#include"../Stack Implementations/Stack_Implementation_Using_Vector.h"
using namespace std;

string reverse(string str){

    Stack<char> s;
    // just insert all characters of a string into stack.
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    //variable to store ans string.
    string ans = "";
    // and the extract each character from stack and store it in ans.
    while (!s.isEmpty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
    
    
}

int main(void){
    
    string str  = "hello world";

    cout<<"Before Reverse:- "<<str<<endl;
    str = reverse(str);
    cout<<"After Reverse:- "<<str<<endl;
    
}