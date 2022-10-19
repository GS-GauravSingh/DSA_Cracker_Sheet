/*
Ques:- Given a valid mathematical expression in form of string, return true if the expression contains pair of redundant brackets else return false.

Redundant bracket means, if a subexpression is surrounded by useless or needless bracket.

Example 1:-  (a+b) => does not have any pair of redindant bracket, + operator consumes outer brackets.

Example 2:- ((a+b)) => outer bracket are redundant (useless/needless), inner brackets are consumed by + operator.


Note:-
if any operator is present in b/w a pair of bracket, it means that pair of bracket is not redundant, it's a valid pair.
Ex:- (a+b),  (a * (b + c))

Approach Steps:-
1. character is a opening bracket or it's a operator push it into stack.

2. if it is a closing bracket, it means for some previous characters you push into stack it must contain an opening bracket for that closing bracket.

So, you just have to check if any operator is present in b/w these pairs of brackets, if yes, then these bracket are not redundant else these brackets are redundant.

*/


/*

Time Complexity:- O(n), n is a length of string.
Space Complexity:- O(n)

*/


#include<bits/stdc++.h>
#include"../Stack Implementations/Stack_Using_Vector.h"
using namespace std;

bool findRedundantBrackets(string str){
    Stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        // if ch is a opening bracket or it's a operator push it into stack.
        char ch = str[i];
        if(ch == '(' || ch == '+' || ch == '-' ||
           ch == '/' || ch == '*')
        {
            s.push(ch);
        }
        // if it is a closing bracket and this pair of bracket are not redundant, there is an operator in b/w these pair of brackets.
        // if there is no operator in b/w these brackets it means this pair of brackets are redundant.
        else{

            // in this case,
            // ch is a closing bracker ')' or it's an lower case character 

            if(ch == ')'){
                // just check if there is any operator present in b/w brackets.

                bool isRedundant = true;

                while(s.peek() != '('){
                    char top = s.peek();
                    if(top == '+' || top == '-' ||
                       top == '/' || top == '*')
                    {
                        isRedundant = false;
                    }
                    s.pop();
                }
                // because this loop will terminate when it find an opening bracket. So, we have to remove this opening bracket.
                s.pop();

                if(isRedundant == true){
                    return true;
                }

            }

        }
    }

    return false;
    
}

int main(){
    string str = "( (a + (b + c) ) )";
    // string str = "(a + (b + c) )";

    if(findRedundantBrackets(str)){
        cout<<"Expression contains redundant brackets.\n";
    }
    else{
        cout<<"Expression does not contain any pair of redundant brackets.\n";
    }
}