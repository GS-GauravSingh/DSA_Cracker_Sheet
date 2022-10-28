// Since we are using vector in this case, there is no need of any other variable like top, size.
// we can easily insert element using push_back(), pop element using pop_back(), peek using back(),
//  and get size of stack using vector.size().

/*

All Methods having constant i.e., O(1) time complexity.

*/
#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class Stack
{
private:
    // all we need is a vector.
    vector<T> arr;
public:
    // Methods

    // method to push element into stack.
    void push(int data){
        // there is no need to check for overflow condition, because can grow itself dynamically.
        arr.push_back(data);
    }

    // method to pop element form stack.
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow.\n";
        }
        else
        {
            arr.pop_back();
        }
    }

    //method to check if stack is empty or not.
    bool isEmpty(){
        if(arr.size()){
            //except 0, if vector has some size it means arr is not empty.
            return false;
        }
        else{
            // if size of vector is 0, it means arr is empty.
            return true;
        }
    }

    // method to get top element of stack.
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty please insert some elements to get the top element.\n";
            return -1;
        }
        else
        {
            // return the last element of vector.
            return arr.back();
        }
    }

    // method to return the size of stack.
    int size()
    {
        return arr.size();
    }
};