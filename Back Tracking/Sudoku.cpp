#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canWePlace(vector<vector<char>>& board, int row, int col, int num) {
    for(int i = 0;i < 9; i++) {
        if(board[row][i] == '0' + num) return false;
    }

    for(int i = 0;i < 9; i++) {
        if(board[i][col] == '0' + num) return false;
    }

    int x = (row/3)*3;
    int y = (col/3)*3;

    for(int i = x; i < x+3; i++) {
        for(int j = y; j < y+3; j++) {
            if(board[i][j] == '0' + num) return false;
        }
    }

    return true;
}

bool f(vector<vector<char>>& board, int r, int c) {
    if(r == 9) return true;
    else if(c == 9) return f(board,r+1,0);
    else if(board[r][c] != '.') return f(board,r,c+1);

    for(int i = 1; i <= 9; i++) {
        if(canWePlace(board,r,c,i)) {
            board[r][c] = '0' + i;

            bool retVal = f(board,r,c+1);
            if(retVal) return true;

            board[r][c] = '.';
        }
    }

    return false;
}
 
void solveSudoku(vector<vector<char>>& board) {
    f(board,0,0);
    return;
}

int main() {
    vector<vector<char>> board = {
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };

    solveSudoku(board);

    for(auto row : board) {
        for(auto x : row) cout << x << " ";
        cout << endl;
    }
}