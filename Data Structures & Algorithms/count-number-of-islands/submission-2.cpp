class Solution {
public:

    int solve(vector<vector<char>>& grid, vector<vector<int>> &visited, int i, int j){
        //base case
        int row = grid.size();
        int col = grid[0].size();

        if(i<0 || i>= row || j<0 || j>= col){
            return 0;
        }

        if(visited[i][j] == 1){
            return 0;
        }

        if(grid[i][j] != '1'){
            return 0;
        }

        visited[i][j] = 1;

        int down = solve(grid, visited, i+1, j);
        int left = solve(grid, visited, i, j-1);
        int right = solve(grid, visited, i, j+1);
        int up = solve(grid, visited, i-1, j);

        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        int ans = 0;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    ans = ans + solve(grid, visited, i, j);
                }
            }
        }

        return ans;
    }
};
