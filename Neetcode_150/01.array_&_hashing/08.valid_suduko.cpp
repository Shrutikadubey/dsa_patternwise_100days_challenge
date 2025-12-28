//daye-28/12/25
//link-https://neetcode.io/problems/valid-sudoku/question
/*Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Example 1:
Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".","5","7","9","2","8","."],[".", ".", ".", "4", "1", "9", ".", ".", "5"], [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
Output: true

Example 2:
Input: board = [["8", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."], [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", "." ,". ", ". ", "6" ,". ", ". ", ". ", "3"], ["4" ,". ", ". ", "8" ,". ", "3" ,". ", ". ", "1"], ["7" ,". ", ". ",". ","2 ",". ",". ",". ","6"], [". ","6 ",". ","5 ","7 ","9 ","2 ","8 ","."], [". ",". ",". ","4 ","1 ","9 ",". "." ,"5"], [". ".". ".". ".". ".". ".". "."]]
Output: false*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<char>> rows(9), cols(9), boxes(9);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c == '.') continue;
            int boxIndex = (i / 3) * 3 + (j / 3);
            if (rows[i].count(c) || cols[j].count(c) || boxes[boxIndex].count(c)) {
                return false;
            }
            rows[i].insert(c);
            cols[j].insert(c);
            boxes[boxIndex].insert(c);
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'1','2','.','.','3','.','.','.','.'},
        {'4','.','.','5','.','.','.','.','.'},
        {'.','9','8','.','.','.','.','.','3'},
        {'5','.','.','.','6','.','.','.','4'},
        {'.','.','.','8','.','3','.','.','5'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','.','.','.','.','.','2','.','.'},
        {'.','.','.','4','1','9','.','.','8'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << isValidSudoku(board) << endl; 
    return 0;
    }
};
