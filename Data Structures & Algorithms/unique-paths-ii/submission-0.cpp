class Solution {
public:

    int solve(vector<vector<int>>& obstacleGrid, int n, int m, int i, int j, vector<vector<int>>& dp){
        //basse case

        if(i >= n || j >= m){
            return 0;
        }

        if(obstacleGrid[i][j] == 1){
            return 0;
        }

        if(i == n-1 && j == m-1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solve(obstacleGrid, n, m, i, j+1, dp);
        int down = solve(obstacleGrid, n, m, i+1, j, dp);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(obstacleGrid, n, m, 0, 0, dp);

    }
};