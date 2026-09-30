class Solution {
public:

    int solve(vector<vector<int>>& grid, vector<vector<int>> &visited, int i, int j){

        int row = grid.size();
        int col = grid[0].size();

        if(j<0 || j>=col || i<0 || i>= row){
            return 0;
        }

        if(grid[i][j] == 0){
            return 0;
        }

        if(visited[i][j] == 1){
            return 0;
        }

        visited[i][j] = 1;

        //down
        int down = 0;
        if(i+1 < row && !visited[i+1][j]){
            down = down + solve(grid, visited, i+1, j);
        }

        //right
        int right = 0;
        if(j+1 < col && !visited[i][j+1]){
            right = right + solve(grid, visited, i, j+1);
        }

        //up
        int up = 0;
        if(i-1 >= 0 && !visited[i-1][j]){
            up = up + solve(grid, visited, i-1, j);
        }

        //left
        int left = 0;
        if(j-1 >= 0 && !visited[i][j-1]){
            left = left + solve(grid, visited, i, j-1);
        }

        return 1 + (down + left + right + up);

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        int maxi = 0;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 1){
                    maxi = max(maxi, solve(grid, visited, i, j));
                }
            }
        }

        

        return maxi;
    }
};
