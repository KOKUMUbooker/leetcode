#include <vector>
#include <iostream>

/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
*/

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        int rowLen {static_cast<int>(board.size())};
        if (rowLen != 9)
            return false;

        for (int i {0}; i < rowLen; ++i)
        {
            int colLen {static_cast<int>(board[i].size())};
            if (colLen != 9)
                return false;

            for (int j {0}; j < colLen; ++j)
            {
                if (board[i][j] == '.')
                    continue;

                if (ExistenceCount(board, i, j, board[i][j]) > 1)
                    return false;
            }
        }

        return true;
    }

private:
    int ExistenceCount(
        const std::vector<std::vector<char>>& grid,
        int row,
        int col,
        char num)
    {
        int count {0};

        // Row
        for (int i {0}; i < grid[row].size(); ++i)
        {
            if (grid[row][i] == num)
                ++count;
        }

        if (count > 1)
            return count;

        // Column
        count = 0;

        for (int i {0}; i < grid.size(); ++i)
        {
            if (grid[i][col] == num)
                ++count;
        }

        if (count > 1)
            return count;

        // 3x3 box
        count = 0;

        int boxRowStart {(row / 3) * 3};
        int boxColStart {(col / 3) * 3};

        for (int r {boxRowStart}; r < boxRowStart + 3; ++r)
        {
            for (int c {boxColStart}; c < boxColStart + 3; ++c)
            {
                if (grid[r][c] == num)
                    ++count;
            }
        }

        return count;
    }
};

int main()
{
    Solution sln;

    std::vector<std::vector<char>> board1{
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

    std::vector<std::vector<char>> board2{
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    std::cout << std::boolalpha;
    std::cout << "Board 1: " << sln.isValidSudoku(board1) << '\n';
    std::cout << "Board 2: " << sln.isValidSudoku(board2) << '\n';

    return EXIT_SUCCESS;
}