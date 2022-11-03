//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*
    Steps:- for each character in postfix expression,

    if(character is operand){
        push it into stack.
    }
    else if(character is operator){
        pop 2 elements from stack, a = top element, b = next element after top.
        calculate result = a operator b;
        and push it into stack.
    }

    // the answer is present at stack top.
    return ans;

    */

    // Function to evaluate a postfix expression.

    // Time Complexity:- O(n) 
    // Space Complexity:- O(n)
    int evaluatePostfix(string expression)
    {
        stack<int> s;
        for (int i = 0; i < expression.length(); i++)
        {
            int ch = expression[i];
            if (ch >= '0' && ch <= '9')
            {
                s.push(ch - '0');
            }
            else
            {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();

                if (ch == '+')
                {
                    s.push(y + x);
                }

                else if (ch == '-')
                {

                    s.push(y - x);
                }

                else if (ch == '*')
                {

                    s.push(y * x);
                }

                else if (ch == '/')
                {

                    s.push(y / x);
                }
            }
        }

        return s.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;

        cout << obj.evaluatePostfix(S) << endl;
    }
    return 0;
}

// } Driver Code Ends