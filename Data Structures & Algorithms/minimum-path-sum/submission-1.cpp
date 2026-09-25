class Solution {
public:

    int solve(vector<vector<int>>& grid, int n, int m, int i, int j, vector<vector<int>> &dp){
        
        // destination
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }

        // invalid path
        if(i >= n || j >= m){
            return INT_MAX;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = INT_MAX;
        int down = INT_MAX;

        if(j + 1 < m){
            right = grid[i][j] + solve(grid, n, m, i, j+1, dp);
        }

        if(i + 1 < n){
            down = grid[i][j] + solve(grid, n, m, i+1, j, dp);
        }

        return dp[i][j] = min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(grid, n, m, 0, 0, dp);
    }
};