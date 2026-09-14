class Solution {
public:

    bool Found(vector<vector<char>>& board, string word, int x, int y, int index, vector<vector<int>> visited){
        int row = board.size();
        int col = board[0].size();

        if((x>=0 && x<=row-1) && (y>=0 && y<=col-1) && visited[x][y] == 0 && board[x][y] == word[index]){
            return true;
        }
        return false;
    }
    
    bool solve(vector<vector<char>>& board, string word, int x, int y, int index, vector<vector<int>> visited){
        // base case

        if(index == word.size()-1){
            return true;
        }

        visited[x][y] = 1;

        // Down
        int newx = x+1;
        int newy = y;
        if(Found(board, word, newx, newy, index+1, visited)){
            if(solve(board, word, newx, newy, index+1, visited)){
                return true;
            }
        }

        // left
        newx = x;
        newy = y-1;
        if(Found(board, word, newx, newy, index+1, visited)){
            if(solve(board, word, newx, newy, index+1, visited)){
                return true;
            }
        }

        // right
        newx = x;
        newy = y+1;
        if(Found(board, word, newx, newy, index+1, visited)){
            if(solve(board, word, newx, newy, index+1, visited)){
                return true;
            }
        }

        // UP
        newx = x-1;
        newy = y;
        if(Found(board, word, newx, newy, index+1, visited)){
            if(solve(board, word, newx, newy, index+1, visited)){
                return true;
            }
        }

        visited[x][y] = 0;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));
        int index = 0;

        for(int i= 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(board[i][j] == word[0]){
                    if(solve(board, word, i, j, index, visited)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
