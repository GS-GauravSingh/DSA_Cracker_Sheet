/*
Ques:- Given a valid mathematical expression in form of string, return true if the expression contains pair of redundant brackets else return false.

Redundant bracket means, if a subexpression is surrounded by useless or needless bracket.

Example 1:-  (a+b) => does not have any pair of redindant bracket, + operator consumes outer brackets.

Example 2:- ((a+b)) => outer bracket are redundant (useless/needless), inner brackets are consumed by + operator.


Note:-
if any operator is present in b/w a pair of bracket, it means that pair of bracket is not redundant, it's a valid pair.
Ex:- (a+b),  (a * (b + c))

Approach Steps:-
1. While iterting through string if a character is a opening bracket or it's a operator push it into stack.

2. if it is a closing bracket, it means for some previous characters you push into stack it must contain an opening bracket for that closing bracket.

So, you just have to check if any operator is present in b/w these pairs of brackets, if yes, then these bracket are not redundant else these brackets are redundant.

*/

/*

Time Complexity:- O(n), n is a length of string.
Space Complexity:- O(n)

*/

#include <bits/stdc++.h>
#include "../Stack Implementations/Stack_Implementation_Using_Vector.h"
using namespace std;

/* Function to check for Redundant Brackets */
bool findRedundantBrackets(string str)
{
    Stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        // if ch is a opening bracket or it's a operator push it into stack.
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            s.push(ch);
        }
        else
        {
            // if it is a closing bracket and this pair of bracket are not redundant, there is an operator in b/w these pair of brackets.
            // if there is no operator in b/w these brackets it means this pair of brackets are redundant.
            if (ch == ')')
            {
                bool isRedundant = true;
                while (s.top() != '(')
                {
                    char top = s.top();
                    if (top == '+' || top == '-' || top == '/' || top == '*')
                    {
                        isRedundant = false;
                    }
                    s.pop();
                }

                if(isRedundant == true){
                    // if isRedundant is true, it means redundant backets are present.
                    // return true.
                    return true;
                }
                // if isRedundant is false, it means current pair of bracket is not redundant,
                // remove the opening bracke from stack and continue the process.
                s.pop();
                // because this loop will terminate when it find an opening bracket. So, we have to remove this opening bracket.
            }
        }
    }
    // at this point the program does not return anything, it means the expression does not contain any redundant brackets. So, return false.
    return false;
}

int main()
{
    string str = "(a+c*b)+(c))";
    // string str = "(a+b)";

    cout<<findRedundantBrackets(str);
    
}