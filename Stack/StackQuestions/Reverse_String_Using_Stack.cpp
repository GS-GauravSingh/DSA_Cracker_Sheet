/*
 it's a very simple question, we know that stack is a lifo kind data structure, so if we insert a string in a stack and when we extract that string back to the stack it came out to be in a reverse order.

Note:- if you insert anything in stack, it came out to be in reverse order.

example:-

Stack Input                              Stack Output
  
   h                                          o
   e                                          l
   l                                          l
   l                                          e
   o                                          h

*/

// Time Complexity:- O(n), n is the length of string.
// Space Complexity:- O(n)

#include<bits/stdc++.h>
// includeing our own stack implementation header file.
#include"../Stack Implementations/Stack_Using_Linked_List.h"
using namespace std;


// function to reverse a string using stack 
void reverse(string &str){
    Stack<char> s;
    // inserting element in stack
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }

    // extracting element from stack and push back in string.
    for(int i=0;i<str.length();i++){
        str[i] = s.peek();
        s.pop();
    }
}

// utility function to print string
void printString(string str){
    for (int i = 0; i < str.length(); i++)
    {
        cout<<str[i]<<" ";
    }
    cout<<"\n";
    
}

int main(){
    string str = "hello";
    cout<<"Before reverse.\n";
    printString(str);

    cout<<"After reverse.\n";
    reverse(str);
    printString(str);
}