class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1);

        for(int i=0; i<=n; i++){
            dp[i] = -1;
        }

        int x = solve(n, dp);
        return x;
    }
};