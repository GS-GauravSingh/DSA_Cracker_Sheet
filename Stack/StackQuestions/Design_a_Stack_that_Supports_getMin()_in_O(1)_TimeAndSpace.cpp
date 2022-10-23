/*

Question:- Design a stack data structure in such a way, so that we can get the minimum element of the stack in O(1) time and space complexity.

Approach 1:- every time you push element into stack, maintain a variable mini to find minimum value and when you push element into stack compare it with mini and store minimum in a seprate data structure.
ex:- int mini = INT_MAX;
      stack
        4    mini = min(mini, 4); mini = 2;
        2    mini = min(mini, 2); mini = 2;
        8    mini = min(mini, 8); mini = 3;
        3    mini = min(mini, 3); mini = 3;
        5    mini = min(mini, 5); mini = 5;

Now, you need to store all values of mini. So, that is someone say let's pop the top element after popping what is the minimum element from element 2 to end. So from 2 to 5 minimum element is 2 we know that because we store all values of mini.

Drawback:- O(n)space is used in this approach, but we need to solve this using O(1) time and space. So, we need to optimized it.

Time complexity: O(1)
        For push(): O(1) - Constant extra space is required.
        For pop(): O(1) - Constant extra space is required.
        For top(): O(1) - Constant extra space is required.
        For getMin(): O(1) - Constant extra space is required.
        For isEmpty(): O(1) - Constant extra space is required.

Space complexity: O(n), extra stack s2 is used.


Approach 2:- Example:-

elements are:- 5,3,8,2,4
int mini = INT_MAX;

------------- for push operation ----------------------

----------- Push Algorithm ------------------
1. check for overflow condition.
2. When we are starting, for 1st element, push element into stack normally and update mini.
above example, when we push 5,
    stack           and     mini = min(mini, 5); {initially mini = INT_MAX}
      5                     mini = 5;

3. for rest elements, compare,
if(currentElement < mini)
{
    // iska matlab ek nayi minimum value milne wali hai.
    int value = 2*curr - mini; // we will see why this works.
    push(value);  // push value into stack.
    update mini;
}
else{
    // if currentElement > mini, simply push it into stack;
    push(curr);
}

for rest of the elemnts in above example,

------------ pushing 3 ------------------

mini = 5; curr = 3;
compare => curr < mini // true;
value = 2*curr-mini;
value = 2*3-5;
value = 1;

push(value);
mini = min(mini, curr);

Now our stack and mini would look like this,
    stack           and     mini = min(mini, curr);
      1                     mini = min(5, 3);
      5                     mini = 3;


------------ pushing 8 ------------------

mini = 3; curr = 8;
compare => curr < mini; // false, means simply push into stack.

Now our stack and mini would look like this,
    stack           and     mini = 3; // no change in mini.
      8
      1
      5
------------ pushing 2 ------------------

mini = 3; curr = 2;
compare => curr < mini; // true.
value = 2*curr-mini;
value = 2*2-3;
value = 1;

push(value);
mini = min(mini, curr);

Now our stack and mini would look like this,
    stack               and     mini = min(mini, curr);
      1                         mini = min(3, 2);
      8                         mini = 2;
      1
      5


------------ pushing 4 ------------------

mini = 3; curr = 4;
compare => curr < mini; // false.

push(curr);


Now our stack and mini would look like this,
    stack               and     mini = 2; // no change in mini.
      4
      1
      8
      1
      5


------------- for pop operation ----------------------
Now our stack and mini would look like this,

    stack               and     mini = 2;
      4
      1
      8
      1
      5

----------- Pop Algorithm ------------------
1. check for underflow condition.
2. if(curr > mini){
    normal pop(); // curr = s.top();
}
else{
    // if curr < mini, in this case we have to update mini like this,
    int value = 2*mini - curr;
    mini = val;

    // and the pop the top element;
    s.pop();
}

ex:- popping in above example,

    stack               and     mini = 2;
      4
      1
      8
      1
      5

popping 4:-
curr = 4; mini = 2;
compare:- curr > mini; // normal pop();
    stack               and     mini = 2;
      1
      8
      1
      5

popping 1:-
curr = 1; mini = 2;
compare:- curr < mini;

value = 2*mini - curr;
value = 2*2 - 1;
value = 3;

pop();

mini = value; // update mini;
    stack               and     mini = 3;
      8
      1
      5

popping 8:-
curr = 8; mini = 3;
compare:- curr < mini; // false, means simple pop()

pop();

mini = value; // update mini;
    stack               and     mini = 3;
      1
      5


popping 1:-
curr = 1; mini = 3;
compare:- curr < mini; // true
value = 2*mini - curr;
value = 2*3-1;
value = 5;

pop();

mini = value; // update mini;
    stack               and     mini = 5;
      5


popping 5:-
curr = 5; mini = 5;
compare:- curr < mini; // false, means simple pop();

pop();

mini = value; // update mini;
    stack               and     mini = 5;
    empty




What these formulas works?
Answer:-
in push, the formula used is:-  2*curr - mini;
in pop, the formula used is:-  2*mini - curr;

we are using these formulas, So that we can find the previous minimum value using current minimum value.


*/
#include <bits/stdc++.h>
using namespace std;

//---------------------- Approach 1:- code ------------------------

class SpecialStack
{
    // Questions states the we need to use in-build stack data structure to implement this specialStack.
    // s2 is to store minimum values
    stack<int> s1, s2;

public:
    void push(int data)
    {
        if (isEmpty())
        {
            // when stack is empty we push element into both stack.
            s1.push(data);
            s2.push(data);
        }
        else
        {
            // when stack is not empty, push element in s1 and push minimum element in s2.
            s1.push(data);
            s2.push(min(data, s2.top()));
        }
    }

    int pop()
    {
        // whenever we pop element from stack, we need to pop element from our minimums stack (s2) also.
        if (isEmpty())
        {
            // if stack is empty return -1.
            return -1;
        }
        // if stack is not empty store the top element then pop it and then return the stored top element..
        int ans = s1.top();
        s1.pop();
        s2.pop();
        return ans;
    }

    int top()
    {
        if (isEmpty())
        {
            // if stack is empty return -1.
            return -1;
        }
        // if stack is not empty return the top element from s1.
        return s1.top();
    }

    bool isEmpty()
    {
        return s1.empty();
    }

    int getMin()
    {
        if (isEmpty())
        {
            // if stack is empty return -1.
            return -1;
        }

        // return the minimum element. We store all our minimum elements in s2.
        return s2.top();
    }
};
//---------------------- Approach 1:- code ends here. ------------------------


//---------------------- Approach 2:- code ------------------------
class SpecialStack {
    stack<int> s;
    int mini;

    public:
        
    void push(int data) {
        // for first element
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            // for remaining element
            if(data < mini){
                int value = 2 * data - mini;
                s.push(value);
                
                // update mini
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        s.pop();
        if(curr > mini){
            return curr;
        }
        else{
            int prevMin = mini;
            int value = 2*mini-curr;
            mini = value;
            return prevMin;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(curr < mini){
            return mini;
        }
        else{
            return curr;
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return s.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()){
            return -1;
        }
        return mini;
    }  
};

int main()
{
}