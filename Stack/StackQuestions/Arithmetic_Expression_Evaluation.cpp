/*

---------------- All About Infix, Postfix and Prefix. --------------------------

Infix Expression:- The expression of the form a operator b. When an operator is in-between every pair of operands.
form :- operand_1 operator operand_2

Example:- a+b, (a-b)*(c-d), (((a-b)+((c*d)/e))+f)
As we know, in school, to solve this type of expression we use the BODMAS rule.

Postfix Expression:- The expression of the form a b operator. When an operator is followed for every pair of operands.
form :- operand_1 operand_2 operator

Prefix Expression:-  form :- operator operand_1 operand_2

Example:-  Infix Expressions      Postfix Expressions       Prefix Expression
    form:-     (a*b)                    (ab*)                   (*ab)
--------------------------------------------------------------------------------
                (a+b)                    ab+                    +ab
                (a+(b*d))                abd*+                   +a*bd
                (a+b)*c)                 ab+c*                   *+abc
                ((x*y)-(z/p))            xy*zp/-                 -*xy/zp

Note:- when we perfom any sort of calculations in our program, our compiler (at compile time) converts infix expression to postfix expression and at runtime, it evaluates that postfix expressions.Because for compiler it is easy to evaluate postfix expression as compare to infix expression.


How to convert infix to postfix:-

Example 1 :- a+b*d

Step 1:-
Apply brackets according to operator precedence and associativity.
above Example after applying brackets:-  (a+(b*d)).


Step 2:-
After applying brackets, first convert innermost bracket.
above Example converting innermost bracket :-  (a+(b*d)) => innermost bracket => (b*d) => convert => bd*


Step 3:-
Now, treat this *bd as a operand and convert rest of the expression.

Expression:- a+(bd*) => convert => abd*+

Done.


Example 2 :- (a+b)*c, bracket is already given in (a+b).

Step 1:-
Apply brackets according to operator precedence and associativity.
above Example after applying brackets:-  ((a+b) * c)


Step 2:-
After applying brackets, first convert innermost bracket.
above Example converting innermost bracket :-  ((a+b) * c) => innermost bracket => (a+b) => convert => ab+


Step 3:-
Now, treat this ab+ as a operand and convert rest of the expression.

Expression:- (ab+ * c) => convert => ab+c*

Done.


Example 3 :- x*y-z/p

Step 1:-
Apply brackets according to operator precedence and associativity.
above Example after applying brackets:-  ((x*y)-(z/p))


Step 2:-
After applying brackets, first convert innermost bracket.
above Example converting innermost bracket :-  ((x*y)-(z/p)) => innermost bracket => (x*y), (z/p) => convert => xy* , zp/


Step 3:-
Now, treat this xy* and z/p as a operand and convert rest of the expression.

Expression:- (xy*-zp/)  => convert => xp*zp/-

Done.

*/

/*
------------------- Program to convert infix to postfix ----------------------------------

Step:-

while traversing the infix expression if we encounter,

1. (        :- push in into stack.
2. operand  :- print it.
3. )        :- keep popping from stack and print till ( is found.
4. operator :-
4.1:- if(stack is empty){
    push operator.
}
4.2:- else{
        4.2.1:- compare current opetrator with the top operator (our stack will have only operators and brackets).
        if(current operator precedence > operator present at stack top){
            push operator.

            // we are maintaining low to high precedence order in stack.
            //example:-    stack
                            *
                            +
            // low precedence operator present at bottom and high precedence operator present at top.
        }
        else{
            // current operator precedence < operator present at stack top
            keep popping elements from stack and print till lower precedence operator is found.
        }

5. once the expression is finished, keep popping from stack and print.
}
*/

#include <bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1; // Precedence of + or - is 1
    }
    else if (ch == '*' || ch == '/')
    {
        return 2; // Precedence of * or / is 2
    }
    else if (ch == '^')
    {
        return 3; // Precedence of ^ is 3
    }
    else
    {
        return 0;
    }
}

string Infix_To_Postfix(string expression)
{
    stack<char> s;
    string ans;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        // if character is and operand, store it in answer string.
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            ans.push_back(ch);
        }
        else if (ch == '(')
        {
            // if character is a opening bracket, push it into stack.
            s.push(ch);
        }
        else if (ch == ')')
        {
            // if character is a closing bracket, pop the stack untill you finde the opening bracket but remenber to store the popped element in answer string..
            while (!s.empty() && s.top() != '(')
            {
                ans.push_back(s.top());
                s.pop();
            }

            // pop the opening bracket.
            s.pop();
        }
        else
        {

            // if character is a operator, check if stack is empty, push it.
            if (s.empty())
            {
                s.push(ch);
            }
            // if stack is not empty, check for precedence,
            // if precedence of ch > precedence of operator present at top, in this case simply push the operator.
            else if(precedence(ch) > precedence(s.top())){
                s.push(ch);
            }

            // if precedence of ch < precedence of operator present at top, in this pop the elemnets from stack until you find the operator of lower precedence, but remember to store the popped element into our answer string.
            else{
                while (!s.empty() && precedence(s.top()) >= precedence(ch)){
                    s.pop();
                    ans.push_back(s.top());
                }

                // when you find the lower precedence operator, 
                // then push ch into stack.
                s.push(ch);
                                
            }
        }
    }

    // once the string expression is finished, keep popping from stack and store the popped element in answer string.
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    //return ans;
    return ans;
    
}

int main()
{
    string expression = "a+(d*e)";
    cout<<Infix_To_Postfix(expression);
}