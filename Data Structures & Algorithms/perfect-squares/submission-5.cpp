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

        int mini = INT_MAX;

        // Try every perfect square <= n
        for(int i = 1; i * i <= n; i++) {

            int ans = solve(n - i * i, dp);

            mini = min(mini, ans);
        }

        return dp[n] = mini + 1;
    }

    int numSquares(int n) {

        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};