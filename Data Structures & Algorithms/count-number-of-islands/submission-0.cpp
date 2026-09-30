class Solution {
public:

    int solve(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j){

        int row = grid.size();
        int col = grid[0].size();

        if(j >= col || j < 0 || i >= row || i < 0){
            return 0;
        }

        if(grid[i][j] == '0'){
            return 0;
        }

        if(visited[i][j] == 1){
            return 0;
        }

        visited[i][j] = 1;

        //down
        if(i+1 < row && !visited[i+1][j]){
            solve(grid, visited, i+1, j);
        }

        //right
        if(j+1 < col && !visited[i][j+1]){
            solve(grid, visited, i, j+1);
        }

        //left
        if(j-1 >= 0 && !visited[i][j-1]){
            solve(grid, visited, i, j-1);
        }

        //up
        if(i-1 >= 0 && !visited[i-1][j]){
            solve(grid, visited, i-1, j);
        }

        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        int ans = 0;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == '1'){
                    ans = ans + solve(grid, visited, i, j);
                }
            }
        }

        return ans;
    }
};
