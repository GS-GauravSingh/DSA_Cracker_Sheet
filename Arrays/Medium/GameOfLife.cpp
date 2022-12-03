#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    // Time Complexity:- O(m*n)
    // Space Complexity:- O(1)
    int liveNeighboursCount(vector<vector<int>> &board, int i, int j)
    {
        int row = board.size();
        int col = board[0].size();

        int liveCount = 0;

        // checking horizontal neighbours.

        // left
        if (j - 1 >= 0)
        {
            if (board[i][j - 1] == 1 || board[i][j - 1] == -1)
            {
                liveCount++;
            }
        }

        // right
        if (j + 1 < col)
        {
            if (board[i][j + 1] == 1 || board[i][j + 1] == -1)
            {
                liveCount++;
            }
        }

        // checking vertical neighbours.

        // top
        if (i - 1 >= 0)
        {
            if (board[i - 1][j] == 1 || board[i - 1][j] == -1)
            {
                liveCount++;
            }
        }

        // bottom
        if (i + 1 < row)
        {
            if (board[i + 1][j] == 1 || board[i + 1][j] == -1)
            {
                liveCount++;
            }
        }

        // checking diagonal neighbours.

        // top left
        if (i - 1 >= 0 && j - 1 >= 0)
        {
            if (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == -1)
            {
                liveCount++;
            }
        }

        // bottom left
        if (i + 1 < row && j - 1 >= 0)
        {
            if (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == -1)
            {
                liveCount++;
            }
        }

        // top right
        if (i - 1 >= 0 && j + 1 < col)
        {
            if (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == -1)
            {
                liveCount++;
            }
        }

        // bottom right
        if (i + 1 < row && j + 1 < col)
        {
            if (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == -1)
            {
                liveCount++;
            }
        }

        return liveCount;
    }

    void gameOfLife(vector<vector<int>> &board)
    {

        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int liveCount = liveNeighboursCount(board, i, j);

                if (board[i][j] == 0)
                {
                    // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                    if (liveCount == 3)
                    {
                        board[i][j] = 2; // 2 means this cell become a live cell.
                    }
                }
                else
                {
                    // live cell, board[i][j] == 1.

                    if (liveCount < 2 || liveCount > 3)
                    {
                        // Any live cell with fewer than two live neighbors dies as if caused by under-population.
                        // And,
                        // Any live cell with more than three live neighbors dies, as if by over-population.
                        board[i][j] = -1; // -1 means this cell become dead cell.
                    }
                }
            }
        }

        // update vector.
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == -1)
                {
                    // -1 means this cell become dead cell.
                    board[i][j] = 0;
                }
                else if (board[i][j] == 2)
                {
                    // 2 means this cell become a live cell.
                    board[i][j] = 1;
                }
            }
        }
    }

    /* Method to print 2D vector. */
    void print(vector<vector<int>> arr)
    {

        for (int i = 0; i < arr.size(); i++)
        {
            int col = arr[i].size();
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */
int main()
{
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0},
    };

    Solution s;
    s.gameOfLife(board);
    s.print(board);
}