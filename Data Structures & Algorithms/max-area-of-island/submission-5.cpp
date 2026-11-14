class Solution {
public:

    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited){
        int row = grid.size();
        int col = grid[0].size();

        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 0 || visited[i][j] == 1){
            return 0;
        }

        visited[i][j] = 1;

        int ans = 0;

        if(i+1 < row && !visited[i+1][j]){
            ans = ans + solve(grid, i+1, j, visited);
        }

        if(i-1 >= 0 && !visited[i-1][j]){
            ans = ans + solve(grid, i-1, j, visited);
        }

        if(j+1 < col && !visited[i][j+1]){
            ans = ans + solve(grid, i, j+1, visited);
        }

        if(j-1 >= 0 && !visited[i][j-1]){
            ans = ans + solve(grid, i, j-1, visited);
        }

        return ans + 1;


    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        int maxi = 0;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int ans = solve(grid, i, j, visited);
                    maxi = max(ans, maxi);
                }
            }
        }

        return maxi;
    }
};
