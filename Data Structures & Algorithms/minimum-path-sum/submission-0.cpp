class Solution {
public:

    int solve(vector<vector<int>>& grid, int n, int m,
              int i, int j, vector<vector<int>>& dp) {

        // destination
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }

        // invalid path
        if(i >= n || j >= m){
            return INT_MAX;
        }

        // already calculated
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solve(grid, n, m, i, j+1, dp);
        int down = solve(grid, n, m, i+1, j, dp);

        int ans = min(right, down);

        // avoid INT_MAX + grid[i][j]
        if(ans == INT_MAX){
            return dp[i][j] = INT_MAX;
        }

        return dp[i][j] = grid[i][j] + ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(grid, n, m, 0, 0, dp);
    }
};