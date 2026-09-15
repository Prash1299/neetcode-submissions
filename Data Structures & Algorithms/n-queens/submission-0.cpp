class Solution {
public:

    void addSolution(vector<vector<char>>& board, vector<vector<string>> &ans, int n){
        vector<string> temp;
        for(int i = 0; i < n; i++){
            string row = "";
            for(int j = 0; j < n; j++){
                row.push_back(board[i][j]);
            }
            temp.push_back(row);
        }
        ans.push_back(temp);

    }

    bool isSafe(vector<vector<char>>& board, int row, int col, int n){
        int x = row;
        int y = col;

        // check for same row
        while(y>=0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
        }

        x = row;
        y = col;

        //check for diagonal
        while(x>=0 && y>=0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
            x--;
        }

        x = row;
        y = col;

        //check for 2nd diagonl

        while(x<n && y>=0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
            x++;
        }

        return true;
    }

    void solve(vector<vector<char>>& board, vector<vector<string>> &ans, int n, int col){
        //base case
        if(col == n){
            addSolution(board, ans, n);
            return;
        }

        for(int row = 0; row<n; row++){
            if(isSafe(board, row, col, n)){
                board[row][col] = 'Q';
                solve(board, ans, n, col+1);
                //backtrack
                board[row][col] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;

        int col = 0;
        solve(board, ans, n, col);
        return ans;
    }
};
