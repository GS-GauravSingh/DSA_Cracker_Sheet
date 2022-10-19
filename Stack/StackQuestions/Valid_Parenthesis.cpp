/*
It's an Important question but the solution of this is very easy.

Approach:- Iterate through the string, while iterating, if it is a opening bracket push it into stack and when a closing bracket come, you have to check if the correcpond opening bracket is present on the top of stack, if it is present pop the top element else return not balanced.

At the end if your stack become empty means string is balanced else not.

Example:- I/O string:- [ { ( ) } ]
sol:- 
Iterate through the string and if a opening bracket come push it into stack.

    Stack                           
      (
      {
      [
 and when closing bracket came we have to check if the correspond opening bracket of that closing barcket is present on the top of the stack
 or not. 

  (  is barcket ke correspong closing brack ) ye hoga.
  [  is barcket ke correspong closing brack ] ye hoga.
  {  is barcket ke correspong closing brack } ye hoga.

Closing bracket came,
    
    str[i] == ) and stack.top() == (, means opening bracket is present.
    pop the top element.

    Stack                           
      {
      [


    str[i] == } and stack.top() == {, means opening bracket is present.
    pop the top element.

    Stack                           
      [

    str[i] == ] and stack.top() == [, means opening bracket is present.
    pop the top element.

    Stack                           

Now stack is empty means expressiong is balanced.


*/

/*

Time Complexity:- O(n), n is the length of string.
Space Complexity:- O(n), stack space.


*/


#include<bits/stdc++.h>
#include"../Stack Implementations/Stack_Using_Vector.h"
using namespace std;

bool Check_For_Valid_Parenthesis(string str){
    Stack<char> s;

    for(int i=0; i<str.length(); i++){
        // if str[i] is opening bracket push it into stack.
        char ch = str[i];

        if(ch == '[' || ch == '{' || ch == '('){
            s.push(ch);
        }
        // if it is not a opening bracket,
        //check for correcpond opening bracket on the top of the stack,
        // if it is present pop the top element and continue the process.
        // else return Not Balanved.
        else{
            if(s.isEmpty() == false){
                // when stack is not empty.
                char top = s.peek();

                if( (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{') ||
                    (ch == ')' && top == '(') )
                {

                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                //if stack is empty return false
                return false;
            }
        }
    }

    // At the end, if your stack is empty means expression is balanced return true, else return false.

    if(s.isEmpty()){
        return true;
    }
    return false;
}

int main(){
    string str = "[{()}]";

    if(Check_For_Valid_Parenthesis(str)){
        cout<<"Balanced.\n";
    }
    else{
        cout<<"Not Balanced.\n";
    }
}