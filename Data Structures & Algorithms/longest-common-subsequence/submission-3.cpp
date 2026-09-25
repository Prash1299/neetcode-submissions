class Solution {
public:

    int solve(string text1, string text2, int i, int j, vector<vector<int>> &dp){
        //base case

        if(i >= text1.length() || j >= text2.length()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solve(text1, text2, i+1, j+1, dp);
        }

        else{
            return dp[i][j] = max(solve(text1, text2, i+1, j, dp), solve(text1, text2, i, j+1, dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return solve(text1, text2, 0, 0, dp);
    }
};
