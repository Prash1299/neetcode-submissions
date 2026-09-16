class Solution {
public:
    
    bool isSafe(int n, vector<vector<char>> &board, int col, int row){

        //same row 
        int x = row; 
        int y = col;
        while(y>=0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
        }

        x = row; 
        y = col;
        while(x>=0 && y>=0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
            x--;
        }

        x = row; 
        y = col;
        while(x<n && y>=0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
            x++;
        }

        return true;
    }

    void solve(int &n, vector<vector<char>>& board, int col, int &count){
        if(col==n){
            count++;
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(n, board, col, row)){
                board[row][col] = 'Q';
                solve(n, board, col+1, count);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int col = 0;
        int count = 0;
        solve(n, board, col, count);
        return count;
    }
};