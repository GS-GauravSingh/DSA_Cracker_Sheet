/*
Ques:- Give a string containing either '{' or '}'. This string is valid if all the brackets are balanced. Balanced means for each opening bracket there must be a closing bracket right to it.

Ex:- {}, {}{}, {{}}, {{{}}} these are valid strings.
Ex:- }{, }{}, {}}{{}, {{}}}{ these are not a valid strings.


Note:- for a valid expression,
1. number of opening brackets = number of closing brackets.
2. every closing bracket should have an opening bracket brfore it
 or every opening bracket must have closing bracket right to it.

So, you need to make this string valid, you can perform following operation, In one operation you can reverse the bracket form '{' to '}' and vice verse.

Return the count of minimum number of brackets you need to reverse so that our string become balanced.

Ex:-   index =>  0 1 2 3
  expression =>  { { { } 

in above example, bracket at index 2,3 are alread balanced. In this case we can reverse bracket at index 1. After reverse our string become  { } { }.

So, in this case we reverse only one bracket, our answer is 1.


Approach:-
1. if string length is odd it is impossible to make string valid, return -1, String length must be even.

2. Remove the valid part from the string.
after removing the valid part, you left with 3 types of invalid strings,
1st => {{{{{ -- so on.
2nd => }}}}} -- so on.
3rd => so on -- }}}}{{{{ -- so on.

3.the string which is left after removing the valid part is one of the above 3 types.

Count the number of Opening and closeing brackets.
ans expression would be ((a+1)/2 + (b+1)/2), a no. of open bracket, b no. of close brackets.

4. return ans = ((a+1)/2 + (b+1)/2);

*/


/*

Time Complexity:- O(n)
Space Complexity:- O(n)

*/

#include<bits/stdc++.h>
#include"../Stack Implementations/Stack_Implementation_Using_Vector.h"
using namespace std;

int findMinimumCost(string str){
    // if length is odd, we canonot make this string valid, return -1.
    if(str.length() & 1){
        return -1;
    }

    // if string length is even then, Remove the valid part.
    Stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {   
        // ch is opening bracket push it into stack.
        char ch = str[i];
        if(ch == '{'){
            s.push(ch);
        }
        else{
            // ch is closing bracket.
            if(s.isEmpty() == false && s.top() == '{'){
                // if open bracket is present is stack pop it.
                s.pop();
            }
            else{
                // if stack does not contain any open bracket.
                s.push(ch);
            }
        }
    }

    // at this point your stack containg invalid expression.
    // count number of opening and closing brackets.
    int closeCount = 0, openCount = 0;
    while (s.isEmpty() == false)
    {
        if(s.top() == '{'){
            openCount++;
        }
        else{
            closeCount++;
        }
        s.pop();
    }

    // ans expression = (a+1)/2 + (b+1)/2;
    int ans = (closeCount + 1)/2 + (openCount + 1)/2;
    // return  ans;
    return ans;

}

int main(void){
    string str = "{{{{";

    cout<<findMinimumCost(str);
}