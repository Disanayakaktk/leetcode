// method 1 ( 2ms Beats 56.55% )

class Solution {
public:
    bool subBox(int i, int j, vector<vector<char>>& board){
        vector<char> rowCheck={};
        for(int y=i; y<i+3; y++) {
            for(int x=j; x<j+3; x++) {
                if(board[y][x] != '.') {
                    for(auto num : rowCheck) {
                        if(board[y][x]==num){
                            return false;
                        }
                    }
                    rowCheck.push_back(board[y][x]);
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // check all rows and columns
        for(int i=0;i<9;i++){
            vector<char> rowCheck={};
            vector<char> columnCheck={};
            for(int j=0;j<9;j++){
                if(board[i][j] != '.') {
                    for(auto num : rowCheck) {
                        if(board[i][j]==num){
                            return false;
                        }
                    }
                    rowCheck.push_back(board[i][j]);
                }
                if(board[j][i] != '.') {
                    for(auto num : columnCheck) {
                        if(board[j][i]==num){
                            return false;
                        }
                    }
                    columnCheck.push_back(board[j][i]);
                }
            }
        }
        // check all boxes
        for(int i=0; i<9; i += 3) {
            for(int j=0; j<9; j += 3) {
                if(!subBox(i, j, board)) {
                    return false;
                }
            }
        }

        return true;
    }
};


// method 2 ( 0ms Beats 100.00% )

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowCheck[9][9] = {false};
        bool columnCheck[9][9] = {false};
        bool boxCheck[9][9] = {false};

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] != '.') {
                    int index = board[i][j] - '1';
                    int boxIndex = (i/3)*3 + (j/3);
                    if(rowCheck[i][index] || columnCheck[j][index] || boxCheck[boxIndex][index]) {
                        return false;
                    }
                    rowCheck[i][index] = columnCheck[j][index] = boxCheck[boxIndex][index] = true;
                }
            }
        }
        return true;
    }
};
