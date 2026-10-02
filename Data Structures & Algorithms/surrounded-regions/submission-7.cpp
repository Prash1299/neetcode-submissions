class Solution {
public:

    void solve2(vector<vector<char>>& board, int i, int j, vector<vector<int>> &visited2){

        int row = board.size();
        int col = board[0].size();

        if(board[i][j] == 'X'){
            return;
        }

        if(visited2[i][j] == 1){
            return;
        }

        visited2[i][j] = 1;

        solve2(board, i+1, j, visited2);
        solve2(board, i, j+1, visited2);
        solve2(board, i-1, j, visited2);
        solve2(board, i, j-1, visited2);

        board[i][j] = 'X';
        
    }

    bool solve1(vector<vector<char>>& board, int i, int j, vector<vector<int>> &visited1){

        int row = board.size();
        int col = board[0].size();

        if(i<0 || i>= row || j < 0 || j >= col){
            return false;
        }

        if(visited1[i][j] == 1){
            return false;
        }

        if(board[i][j] == 'X'){
            return false;
        }

        visited1[i][j] = 1;

        bool touchesBoundary = (i == 0 || i == row - 1 || j == 0 || j == col - 1);

        bool down = solve1(board, i+1, j, visited1);

        bool right = solve1(board, i, j+1, visited1);

        bool up = solve1(board, i-1, j, visited1);
        
        bool left = solve1(board, i, j-1, visited1);
        

        return (touchesBoundary || down || right || left || up);
        
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<int>> visited1(row, vector<int>(col, 0));
        vector<vector<int>> visited2(row, vector<int>(col, 0));

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(board[i][j] == 'O' && !visited1[i][j]){
                    bool ans = solve1(board, i, j, visited1);
                    if(!ans){
                        solve2(board, i, j, visited2);
                    }
                }
            }
        }
    }
};
