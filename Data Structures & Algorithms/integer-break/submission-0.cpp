class Solution {
public:

    int solve(int n, vector<int> &dp){
        if(n == 0){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int maxi = 0;

        for(int i = 1; i<n; i++){
            int x = i * max(n-i, solve(n-i, dp));
            maxi = max(maxi, x);
        }

        return dp[n] = maxi;

    }

    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        
        return solve(n, dp);
    }
};