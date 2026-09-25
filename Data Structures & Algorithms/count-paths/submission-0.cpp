class Solution {
public:


    int solve(vector<vector<int>>& grid, int m, int n, int i, int j, vector<vector<int>> &dp){

        if(i == m-1 || j == n-1){
            return 1;
        }

        if(i >= m && j >= n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        //right
        int right = solve(grid, m, n, i, j+1, dp);

        //down
        int down = solve(grid, m, n, i+1, j, dp);


        return dp[i][j] = right + down;

    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, m, n, 0, 0, dp);
    }
};
