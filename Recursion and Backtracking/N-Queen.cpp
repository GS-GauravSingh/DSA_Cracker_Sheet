#include <bits/stdc++.h>
using namespace std;

/* Function to print 2d vector. */
void printVec(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool canPlace(int row, int col, vector<vector<int>> &board, int n)
{
    int r = row, c = col;

    // left row
    while (c >= 0)
    {
        if (board[r][c] == 1)
        {
            return false;
        }
        c--;
    }

    // left diagonal
    r = row, c = col;
    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == 1)
        {
            return false;
        }
        r--;
        c--;
    }

    // bottom-left diagonal
    r = row, c = col;
    while (r < n && c >= 0)
    {
        if (board[r][c] == 1)
        {
            return false;
        }
        r++;
        c--;
    }

    return true;
}

void solveNQueen(vector<vector<int>> &board, int n, int col)
{
    // Base Case
    if (col == n)
    {
        printVec(board);
        return;
    }

    // Recursive Case
    for (int row = 0; row < n; row++)
    {
        if (canPlace(row, col, board, n))
        {
            board[row][col] = 1;
            solveNQueen(board, n, col + 1);
            board[row][col] = 0;
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> board = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},

    };
    solveNQueen(board, n, 0);
}