#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canPlaceQueen(int row, int col, int n,vector<vector<char>>& queenposition) {
    
    // check from attack from top
    for(int i = row-1; i >= 0; i--) {
        if(queenposition[i][col] == 'Q') return false;
    }

    // left diagonal attack
    for(int i = row-1,j = col-1;i >= 0 and j >= 0; i--,j--) {
        if(queenposition[i][j] == 'Q') return false;
    }

    // right diagonal check
    for(int i = row-1,j = col+1; i >= 0 and j < n; i--, j++) {
        if(queenposition[i][j] == 'Q') return false;
    }
    
    return true;
}

void fillQueens(int row,int n,vector<vector<string>>& answer, vector<vector<char>>& queenposition) {
    if(row == n) {
        vector<string> config;

        for(auto row : queenposition) {
            string str = "";

            for(auto x : row) {
                str += x;
            }

            config.push_back(str);
        }

        answer.push_back(config);
        return;
    }

    

    for(int col = 0; col < n; col++) {
        
        if(canPlaceQueen(row,col,n,queenposition)) {
            queenposition[row][col] = 'Q';
            fillQueens(row+1,n,answer,queenposition);
            queenposition[row][col] = '.';
        }

    }
}

vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> answer;
    vector<vector<char>> queenposition(n,vector<char>(n,'.'));
    
    fillQueens(0,n,answer,queenposition);

    return answer;
}

int main() {
    int n = 5;
    vector<vector<string>> queenposition = solveNQueens(n);

    int i = 1;
    for(auto row : queenposition) {
        cout << "Configuration " << i << " is -> ";
        for(auto pos : row) cout << pos << "  ";
        cout << endl;
        i++;
    }

    cout << endl;
}