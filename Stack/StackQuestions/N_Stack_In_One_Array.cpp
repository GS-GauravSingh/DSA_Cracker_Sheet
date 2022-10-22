/*

Question:- Design a Data structure to implement N stacks using a single array of size S. It should support the following operation,
1. push(x,m) => push x in mth stack. return true is element is pushed else return false.
2. pop(m) => pop the top element from the mth stack, return 01 if stack is empty else return popped element.


Approach 1:- suppose the size of array is N and you need to implement k stacks in array of size N. So. what you can do is divide the whole array into equal into k part of equal size and perform operation on it.

Example:-                
Array of size N => |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
     index =>       0  1   2  3  4  5  6  7  8  - - - -  - -  - - - n-1

Suppose you need to implement K stack in above array,

Length of entire array => N, 
divide array into K parts => the length of each part of N/K. After that you can perfor push, pop operation in whichever part you wants.

But the biggest drawback of this approach is, it is not space optimized. Suppose you are trying to push elements more than the length of paticular stack i.e., N/k, you cannot do this because you divide array into k part and each part have same length i.e., N/k you cannot push element more than N/k in each part.

Approach 2:- Example:- let's say we have an arrys of size 9;

Array[9] =>     |__|__|__|__|__|__|__|__|__|
index =>         0  1  2  3  4  5  6  7  8 

and the value of K is 3, means you need to implement 3 stack in above array of size 9.

So, in this approach you need 2 additional thing i.e., 
1st is top[] array of size k, represent index of top element. [k stack ke jo top element honge unka index store karega ye top[] array].

2nd is next[] array containg 2 type of things,
1st is, when there is no element inserted in array, it points to next free space/block.

2nd is, it points to first element after stack top().
ex:- stack
       9
       8  <= first element after stack top().
       7


Let's dry run our approach 2 in an example,
Example:- N -> number of stacks = 3,
          S -> size of array 6,
          Q -> number of queries = 5. 
        [Q1 - push(10, 1), Q2 - push(20, 1), Q3 - push(30, 2), Q4 - pop(1), Q5 - pop(2)]
        push(x,m), means push x in mth stack,
        pop(m), means pop the top element from mth stack.

        
        3 stack be s1,s2,s3.
        Array[6] =>     |__|__|__|__|__|__|  
        index =>         0  1  2  3  4  5  

--------- Initializing top and next array ---------------------------
        k = 3;
        top[k] => |-1|-1|-1| => initially all elements of top is -1, because there in no element.
        index =>   0  1  2 

        S = 6;
        next[6] = |1|2|3|4|5|-1|
        index =>   0 1 2 3 4 5  
        ,next array store the next free space, original array me index 0 ke baad next free space index 1 hai, aise hi index 1 ke baad 2 hai, 3 ke baad 4 hai, 4 ke baad 5 hai and 5 ke baad kuch nhi toh -1. 

        we need one more variable,

        freeSpot ->  next array stores the data of next free space and freeSpot is used to represent the starting index for next array.
        freeSopt = 0; first free space is 0, in original array.

--------------- Queries -------------------------------------------
1. push(10, 1) => push element 10 in 1st stack.

How?
Steps:-
1. find index, hume pta bhi toh hona chahiyea ki kis index pe element push krna hai.
int index = freeSpot;  freeSpot -> stores the starting index.

2. update freeSpot.  freeSpot = next[index]; next[] store the next free space.

3. insert the element.  arr[index] = 10; after inserting array would look like this,
Array[6] =>     |10|__|__|__|__|__|  
index =>         0  1  2  3  4  5  

So, we know our next array store 2 things, 1st is next free space and 2nd is point to first element after stack.top();
So, we need to update out next array.

And,

After Element is inserted, we need to update our top array also. 

4. update next, next[index] = top[m-1], m-1 is index of inserted element i.e., inserted element is 10 woth index 0, m is a variable.

5. update top array, top[m-1] = index;


Solve:- 
1. push(10, 1) => push element 10 in 1st stack.

    index = freeSpot; {freeSpot points to 0 initially} // index nikala.
    freeSpot = next[index]; {next[index] = 1 , freeSpot =  1} // freeSpot update kiya
    arr[index] = 10; // element insert kr diya.
    next[0] = top[0]; {top[0] = -1} // element insert krne ke baar next store krega, first element after stack.top().
    top[0] = index; 

    Array, top[] and next[] would look like this,

    Array[6] =>     |10|__|__|__|__|__|  
    index =>         0  1  2  3  4  5  

    k = 3;
    top[k] => |0|-1|-1| , represent index of top element.
    index =>   0  1  2 

    S = 6;
    next[6] = |-1|2|3|4|5|-1|
    index =>   0  1 2 3 4 5  
    ,next[0] = -1, because after 10 is inserted next[0] store the first element after stack.top(), and in this case first element after stack.top() is -1(because there is no element).

2. push(20, 1) => push element 10 in 1st stack.

    index = freeSpot; {freeSpot = next[index], in above case when index is 0 next[0] is 1, freeSpot = 1} // index nikala.
    freeSpot = next[index]; {next[index] = 2 , freeSpot =  2} // freeSpot update kiya
    arr[index] = 20; // element insert kr diya.
    next[index] = top[0]; {top[0] = 10} // element insert krne ke baar next store krega, first element after stack.top().
    top[0] = index;

    Array, top[] and next[] would look like this,

    Array[6] =>     |10|20|__|__|__|__|  
    index =>         0  1  2  3  4  5  

    k = 3;
    top[k] => |0|1|-1| , represent index of top element.
    index =>   0 1  2 

    S = 6;
    next[6] = |-1|10|3|4|5|-1|
    index =>   0  1 2 3 4 5  
    ,next[1] = 10, because after 20 is inserted next[1] store the first element after stack.top(), and in this case first element after stack.top() is 10. 
    
*/

// ---------------- Without dry run you understand nothing in this question, dry run below steps. ----------------
// Time Complexity:- O(1)
// Space Complexity:- O(s+s+n) => O(2s+n) => O(s+n)

#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;
    
    int n, s;
    int freespot;
    
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        //initializing top array
        for(int i=0; i<n; i++) {
            top[i] = -1;
        }
        
        //initializing next array
        for(int i=0; i<s; i++) {
            next[i] = i+1;
        }
        
        //update last index value to -1, becauyse ther is no next free space  for last index.
        next[s-1] = -1;
        
        //initialise freespot
        freespot = 0;
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for overflow
        if(freespot == -1) {
            // freeSpot = -1, means there is no space for insertion.
            return false;
        }
        
        //find index, where you want to insert element.
        int index = freespot;
        
        //insert element into array
        arr[index] = x;
        
        //update freespot
        freespot = next[index];
       
        //update next;
        next[index] = top[m-1];
        
        //update top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check underflow condition
        if(top[m-1] == -1) {
            return -1;
        }
        
        int index= top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freespot;
        
        freespot = index;
        
        return arr[index];
    }
};

int main()
{
}