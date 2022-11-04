//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution
{
public:
    /*
     Approach 1:- using stack.
     in starting, push -1 inot stack.

     There is only two case,
     if(character is a opening bracket '(' ){
         push index of character into stack.
     }
     else{
         // if character is an closing bracket, then check,
         if(stack is empty){
             push index of ch into stack.
         }
         else{
             pop the top element, and compute length but before computing check for empty stack.
             if(stack is empty){
                 push index of ch.
             }
             else{
                 compute length.
             }
         }

     }


     Example 1:- in this example, you will understand why we're pushing -1 into stack.

     I/O :- (()())
     O/P :- 6

     Solution:-index  =>  0 1 2 3 4 5            Stack
               String =>  ( ( ) ( ) )             -1

     int maxLen = INT_MIN;
     char ch = str[i];
     When i = 0, ch is a opening bracket, push index into stack,
     Stack
       0
      -1

     When i = 1, ch is a opening bracket, push index into stack,
     Stack
       1
       0
      -1

     When i = 2, ch is a closing bracket,check if stack is empty, if yes push index of ch into stack,
     if no, pop the top element from stack, after popping, the check againg for empty stack,
     if stack is empty, push index of ch into stack, else compute length.
     Stack
       1
       0
      -1

     stack is not empty, pop the top element.
     Stack
       0
      -1

     after popping, stack is not empty.
     len = i - s.top(); // s.top() = 0, i = 2, so len = 2;
     maxLen = max(maxLen, len);   // maxLen = max(INT_MIN, 2); maxLen = 2.

     When i = 3, ch is a opening bracket, push index into stack,
     Stack
       3
       0
      -1

     When i = 4, ch is a closing bracket,check if stack is empty, if yes push index of ch into stack,
     if no, pop the top element from stack, after popping, the check againg for empty stack,
     if stack is empty, push index of ch into stack, else compute length.
     Stack
       3
       0
      -1

     stack is not empty, pop the top element.
     Stack
       0
      -1

     after popping, stack is not empty.
     len = i - s.top(); // s.top() = 0, i = 4, so len = 4;
     maxLen = max(maxLen, len);   // maxLen = max(2, 4); maxLen = 4.


     When i = 5, ch is a closing bracket,check if stack is empty, if yes push index of ch into stack,
     if no, pop the top element from stack, after popping, the check againg for empty stack,
     if stack is empty, push index of ch into stack, else compute length.
     Stack
       0
      -1

     stack is not empty, pop the top element.
     Stack
      -1

     after popping, stack is not empty.
     len = i - s.top(); // s.top() = -1, i = 5, so len = -1-5 = 6;
     maxLen = max(maxLen, len);   // maxLen = max(4, 6); maxLen = 6.


     So, maximum length is 6.
     So, initially if we don't push -1 into stack. So, in the last when i = 5, while computing length s.top() will give segmentation fault.

    Time Complexity:- O(n)
    Space Complexity:- O(n)
    */
    int findMaxLen(string str)
    {
        stack<int> s;
        s.push(-1);

        int maxLength = 0;
        for (int i = 0; i < str.length(); i++)
        {

            char ch = str[i];
            // if ch is opening bracket push index of ch into stack.
            if (ch == '(')
            {
                s.push(i);
            }
            else
            {
                // in this case, ch is a closing bracket,
                // pop the top element and compute length.
                if (s.empty())
                {
                    // if stack is empty, push the current index.
                    s.push(i);
                }
                else
                {
                    s.pop();
                    if (s.empty())
                    {
                        s.push(i);
                    }
                    else
                    {
                        int len = i - s.top();
                        maxLength = max(len, maxLength);
                    }
                }
            }
        }

        return maxLength;
    }

    /*

    Optimized Approach:- using two pointers.

    Example:- str =  ")()()(";

    Steps:- iterate through the string,
    initialize 2 variable open and close to count number of open and closing brackets.

    int open =0, close = 0;
    for(int i=0;i<str.length();i++){
        // if count the number of open and close brackets.
        if(str[i] == '('){
            open++;
        }
        else{
            close++;
        }

        // Now if open == close, then this is a vlaid string, compute length.
        if(open == close){
            maxLen = max(maxLen, open+close);
        }
        else if(no. close brackets > no. open brackets){
            //Imp. case.
            open = close = 0;
        }
    }
    Approach not ends here, see example 2.

    Example:-index =>   0 1 2 3 4 5
                str =  ") ( ) ( ) (";

    when i=0,
    open = 0, close = 1;
    close > open, open = close = 0;

    when i=1,
    open = 1, close = 0;
    no condition is true.

    when i=2,
    open = 1, close = 1;
    maxLen = 2;

    when i=3,
    open = 2, close = 1;

    when i=4,
    open = 2, close = 2;
    mexLen = open+close = 4;

    when i=5,
    open = 3, close = 2;

    loop ends..

    maxLen = 4;

    Example 2:-
    index =>  0 1 2 3
    Str =   " ( ( ) ("

    when i=0,
    open = 1, close = 0;

    when i=1,
    open = 2, close = 0;

    when i=3,
    open = 2, close = 1;

    when i=4,
    open = 3, close = 1;

    So, for this test case our maxLen is 0, because our provided coditions are not true for any value of i.

    So,what we will do is after the above loop ends, start checking again from the back side.
    When we are looking from the right this bracket ( becomes this ) and ) becomes this (.

    index =>  0 1 2 3
    Str =   " ) ( ) )";

    while i=0,
    open = 0, close = 1;
    close > open, open = close = 0.

    while i=1,
    open = 1, close = 0;

    while i=2,
    open = 1, close = 1;
    maxLen = max(maxLen , open+close); // maxLen = 2;

    while i=3,
    open = 1, close = 2;

    loop ends..

    maxLen = 2;

    Time Compleixty:- O(n)
    Space Compleixty:- O(1)

    */
    int findMaxLen(string str)
    {
        int open = 0, close = 0;
        int maxLen = 0;

        // checking from left to right.
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (ch == '(')
            {
                open++;
            }
            else
            {
                close++;
            }

            if (open == close)
            {
                maxLen = max(maxLen, open + close);
            }
            else if (close > open)
            {
                open = close = 0;
            }
        }

        // Now check from right to left.
        open = 0, close = 0;
        for (int i = str.length() - 1; i >= 0; i--)
        {
            char ch = str[i];
            if (ch == '(')
            {
                close++;
            }
            else
            {
                open++;
            }

            if (open == close)
            {
                maxLen = max(maxLen, open + close);
            }
            else if (close > open)
            {
                open = close = 0;
            }
        }

        return maxLen;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends