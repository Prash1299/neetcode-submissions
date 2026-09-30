class Solution {
public:

    int solve(vector<vector<int>>& grid, vector<vector<int>> &visited, int i, int j){
        int row = grid.size();
        int col = grid[0].size();

        //base case
        if(i >= row || i < 0 || j >= col || j < 0){
            return 1;
        }

        if(grid[i][j] != 1){
            return 1;
        }

        if(visited[i][j]){
            return 0;
        }

        visited[i][j] = 1;

        int ans = 0;

        ans = ans + solve(grid, visited, i+1, j);
        ans = ans + solve(grid, visited, i, j-1);
        ans = ans + solve(grid, visited, i, j+1);
        ans = ans + solve(grid, visited, i-1, j);

        return ans;

    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j]==1){
                    return solve(grid, visited, i, j);
                }
            }
        }

        return -1;
    }
};