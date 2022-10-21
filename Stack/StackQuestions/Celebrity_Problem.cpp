/*
Question in short:- Everyon knows celebrity but celebrity does not know anyone. If you go to a party of N people, find if there is a celebrity or not.

Given a square matrix of 0 and 1 called as M of size N, representing the people at the party, if M[i][j] = 1 means ith person knows jth personn else M[i][j] = 0.

Ex:-M =  {
    Row index(below)      0 1 2  <= Column index
                    0    {0,1,0},
                    1    {0,0,0},
                    2    {0,1,0}

    }

    M[i][j] = 1, means ith person knows jth person.
    ex:- Row = 0, col = 1, means M[0][1] = 1, means 0th person knows 1th person.

    M[i][j] = 0, means ith persondoes not know jth person.
    ex:- Row = 0, col = 2, means M[0][2] = 0, means 0th person does not knows 2th person.

    Note:- ignore the diagonal elements. The reason is, in case of diagonal elements i == j, means we are talking about same person and it's obvious that a person know itself.

    So, answer of above examples is 1 (Row). Means 1 is a celebrity.

    Because 1 does not know anyone and eyeryone knows 1{ M[0][1] = 1, M[2][1] = 1 }.

Approach:- Brute force



 Time complexity :- O(n^2)
 Space complexity :- O(1)
*/

#include<bits/stdc++.h>
using namespace std;

//--------------------- Brute Force Approach ------------------------

//jo bhi celebrity hoga uski row me saare elements 0 honge, and uske colume me saare elements 1 honge except diagonal element and that row is our celebrity.

// Time complexity :- O(n^2)
// Space complexity :- O(1)

int celebrityProblem_BruteForce(vector<vector<int> >& M, int n){
    // first we need to identify the row in which all elemnts are 0.
    int rowIndex = 0;
    bool isCelebrity = false;
    for (int row = 0; row < n; row++)
    {
        bool found = false;
        for (int col = 0; col < n; col++)
        {
            if(M[row][col]==0){
                found = true;
            }
            else{
                found = false;
                // if a row contain a single 1 in that case break.
                break;
            }
        }

        // after finding the row which contains all 0's.
        if(found == true){
            // and then, we need to check if the column of that row contains all 1's
            // if yes, the that row is a celebrity, else in this case there is no celebrity return -1.
            for (int i = 0; i < n; i++)
            {
                if(i == row){
                    // ignore diagonal element.
                    continue;
                }
                else if(M[i][row] == 1){
                    isCelebrity = true;
                }
                else{
                    isCelebrity = false;
                }
            }
            
        }

        // if we found the row which contains all 0's and column of that row contains all 1's except diagonal element return that row.
        if(isCelebrity == true){
            return row;
        }

    }

    return -1; 
    
}


//------------------------ Optimized Approach -------------------------------

/*

Using Stack:- 
Steps:- 
1. insert all elements into stack.
2. jab tak stack ka size 1 nhi ho jata, stack me se 2 elements nikal lo.
   
   A = s.top();
   s.pop();
   B = s.top();
   s.pop();

   Ab yha se 2 case banenge,
   if(A knows B){
    agar A, B ko janta hai toh A celebrity nhi ho skta, toh A ko discard krdo of B ko vapas daldo.
   }
   if(B knows A){
    agar B, A ko janta hai toh B celebrity nhi ho skta, toh B ko discard krdo of A ko vapas daldo.
   }

3. last me jo single element bachega stack me vo celebrity ho skta hai toh verify krlo.
check if it is a celebrity, it's row must have all 0's and col must have all 1's except diagonal element.

// Time complexity :- O(n)
// Space complexity :- O(n)

*/ 

bool knows(vector<vector<int>>& M, int a, int b){
    // if M[a][b] == 1, means a know b, else not.
    return M[a][b];

}

int celebrity_Optimized(vector<vector<int>>& M, int n){
    //step 1:- push all elements (means index) into stack.
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // Step 2:- get 2 element and compare them.
    while(s.size() > 1){
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        // if a knows b
        if( knows(M,a,b) ){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int candidate = s.top();

    //Step 3:- verify last element of stack.

    // Row checking
    bool rowCheck = false;
    for (int i = 0; i < n; i++)
    {
        if(M[candidate][i] == 0){
            rowCheck = true;
        }
        else{
            rowCheck = false;
            break;
        }
    }

    // Column checking
    bool colCheck = false;
    for (int i = 0; i < n; i++)
    {
        if(i == candidate){
            // ignoring diagonal element
            continue;
        }
        if(M[i][candidate] == 1){
            colCheck = true;
        }
        else{
            colCheck = false;
            break;
        }
    }

    if(rowCheck && colCheck){
        return candidate;
    }
    return -1;   

}
int main(){
    vector<vector<int>> M = {
        {0,1,0},
        {0,0,0},
        {0,1,0},
    };

    int n = M.size();

    cout<<celebrity_Optimized(M,n);
}