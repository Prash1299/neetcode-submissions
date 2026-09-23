class Solution {
public:

    int solve(int n, vector<int>& dp) {

        // Base case
        if(n == 0) {
            return 0;
        }

        // Already calculated
        if(dp[n] != -1) {
            return dp[n];
        }

        int mini = n;

        // Try every perfect square <= n
        for(int i = 1; i * i <= n; i++) {

            int ans = solve(n - i * i, dp);

            mini = min(mini, 1+ans);
        }

        return dp[n] = mini;
    }

    int numSquares(int n) {

        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};