#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Recursive function to solve the Sudoku board
    bool solve(vector<vector<char>>& board, int row, int col, 
               int (&rowMap)[9][9], int (&colMap)[9][9], int (&boxMap)[9][9]) {
        // If we have filled all rows, Sudoku is solved
        if (row == 9) return true;

        // Move to the next row if we reached the last column
        if (col == 9) return solve(board, row + 1, 0, rowMap, colMap, boxMap);

        // If the current cell already has a number, move to the next column
        if (board[row][col] != '.') return solve(board, row, col + 1, rowMap, colMap, boxMap);

        // Identify the 3×3 box index (each box is numbered from 0 to 8)
        int boxIndex = (row / 3) * 3 + (col / 3);

        // Try placing numbers 1-9
        for (int num = 0; num < 9; num++) {
            // Check if the number is already used in the row, column, or box
            if (rowMap[row][num] || colMap[col][num] || boxMap[boxIndex][num]) continue;

            // Place the number
            board[row][col] = num + '1';  // Convert (0-8) to ('1'-'9')
            rowMap[row][num] = colMap[col][num] = boxMap[boxIndex][num] = 1;

            // Recursively try to solve the next cell
            if (solve(board, row, col + 1, rowMap, colMap, boxMap)) return true;

            // If it didn't work, undo the placement (backtrack)
            board[row][col] = '.';
            rowMap[row][num] = colMap[col][num] = boxMap[boxIndex][num] = 0;
        }

        // No valid number found, return false (backtrack)
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        // Maps to track which numbers are used in each row, column, and box
        int rowMap[9][9] = {0}, colMap[9][9] = {0}, boxMap[9][9] = {0};

        // Initialize maps based on the existing numbers in the Sudoku board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';  // Convert character '1'-'9' to index 0-8
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    rowMap[i][num] = colMap[j][num] = boxMap[boxIndex][num] = 1;
                }
            }
        }

        // Start solving from the top-left cell (0,0)
        solve(board, 0, 0, rowMap, colMap, boxMap);
    }
};
