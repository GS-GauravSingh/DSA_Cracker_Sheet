// Since we are using vector in this case, there is no need of any other variable like top, size.
// we can easily insert element using push_back(), pop element using pop_back(), peek using back(),
//  and get size of stack using vector.size().

/*

All Methods having constant i.e., O(1) time complexity, except print having O(n) time complexity (because we are printing all elements) .

*/


#include <iostream>
#include <vector>
using namespace std;

template <typename T>

class Stack
{
private:
    vector<T> arr;

public:
    // methods

    // method to push element into stack.
    void push(int data)
    {
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

    // method to get top element of stack.
    T peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty please insert some elements.\n";
        }
        else
        {
            return arr.back();
        }
    }

    // method to check if stack is empty or not.
    bool isEmpty()
    {
        if (arr.size())
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    // method to return the size of stack.
    int size()
    {
        return arr.size();
    }

    // additional method to print vector.
    void print()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty.\n";
        }
        else
        {
            for (int i = arr.size() - 1; i >= 0; i--)
            {
                cout << arr[i] << "\n";
            }
            cout << "\n";
        }
    }
};
