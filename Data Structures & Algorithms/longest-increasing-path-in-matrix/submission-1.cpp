class Solution {
public:

    int solve(vector<vector<int>> &matrix, int row, int col, int i, int j, vector<vector<int>>& dp){
        if(i >= row || i < 0 || j >= col || j < 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;

        //down
        int down = 0;
        if(i + 1 < row && matrix[i][j] < matrix[i+1][j]){
            down = 1 + solve(matrix, row, col, i+1, j, dp);
        }

        //down
        int up = 0;
        if(i - 1 >= 0 && matrix[i][j] < matrix[i-1][j]){
            up = 1 + solve(matrix, row, col, i-1, j, dp);
        }

        //down
        int left = 0;
        if(j-1 >= 0 && matrix[i][j] < matrix[i][j-1]){
            left = 1 + solve(matrix, row, col, i, j-1, dp);
        }

        //down
        int right = 0;
        if(j+1 < col && matrix[i][j] < matrix[i][j+1]){
            right = 1 + solve(matrix, row, col, i, j+1, dp);
        }

        ans = max(down, max(up, max(left, right)));

        return dp[i][j] = ans;

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int mini = INT_MAX;
        int maxi = INT_MIN;

        vector<vector<int>> dp(row+1, vector<int>(col+1, -1));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                mini = min(matrix[i][j], mini);
                maxi = max(maxi, solve(matrix, row, col, i, j, dp));
            }
        }

        return maxi+1;
    }
};
