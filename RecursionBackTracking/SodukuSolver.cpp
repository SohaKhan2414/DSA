
#include <iostream>
using namespace std;

const int N = 9;

bool isSafe(char board[N][N], int row, int col, char dig)
{
    // Check horizontal row
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == dig)
            return false;
    }

    // Check vertical column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == dig)
            return false;
    }

    // Check 3x3 grid
    int srow = (row / 3) * 3;
    int scol = (col / 3) * 3;

    for (int i = srow; i < srow + 3; i++)
    {
        for (int j = scol; j < scol + 3; j++)
        {
            if (board[i][j] == dig)
                return false;
        }
    }

    return true;
}

bool solveSudoku(char board[N][N], int row, int col)
{
    // Base case: all rows completed
    if (row == 9)
        return true;

    // Calculate next cell
    int nextRow = row;
    int nextCol = col + 1;

    if (nextCol == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    // If cell is already filled, skip it
    if (board[row][col] != '.')
    {
        return solveSudoku(board, nextRow, nextCol);
    }

    // Try digits 1 to 9
    for (char dig = '1'; dig <= '9'; dig++)
    {
        if (isSafe(board, row, col, dig))
        {
            board[row][col] = dig;

            // Recursive call for next cell
            if (solveSudoku(board, nextRow, nextCol))
                return true;

            // Backtracking
            board[row][col] = '.';
        }
    }

    return false;
}

void printBoard(char board[N][N])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    char board[9][9] =
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (solveSudoku(board, 0, 0))
    {
        cout << "Solved Sudoku:" << endl;
        printBoard(board);
    }
    else
    {
        cout << "No solution exists." << endl;
    }

    return 0;
}
