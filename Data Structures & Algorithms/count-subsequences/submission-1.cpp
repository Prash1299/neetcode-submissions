class Solution {
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>>& dp){

        if(j == t.length()){
            return 1;
        }

        if(i == s.length()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;

        if(s[i] == t[j]){
            ans = solve(s, t, i+1, j+1, dp) + solve(s, t, i+1, j, dp);
        }

        else{
            return solve(s, t, i+1, j, dp);
        }

        return dp[i][j] = ans;

    }

    int numDistinct(string s, string t){
        vector<vector<int>> dp(s.length()+1, vector<int>(t.length(), -1));
        return solve(s, t, 0, 0, dp);
    }
};
