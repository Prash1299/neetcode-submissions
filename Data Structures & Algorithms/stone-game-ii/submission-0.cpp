class Solution {
public:

    int solve(vector<int>& piles,
              int index,
              int M,
              vector<int>& suffix,
              vector<vector<int>>& dp) {

        // No piles remaining
        if(index >= piles.size()) {
            return 0;
        }

        // Already calculated
        if(dp[index][M] != -1) {
            return dp[index][M];
        }

        int ans = 0;

        // Try taking X piles
        for(int X = 1; X <= 2 * M && index + X <= piles.size(); X++) {

            int newM = max(M, X);

            // Opponent's maximum score
            int opponent =
                solve(piles, index + X, newM, suffix, dp);

            // Total stones remaining from index
            int total = suffix[index];

            // Current player gets total - opponent
            int currentPlayer = total - opponent;

            ans = max(ans, currentPlayer);
        }

        return dp[index][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        // suffix[i] = total stones from i to n-1
        vector<int> suffix(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        // dp[index][M]
        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        return solve(piles, 0, 1, suffix, dp);
    }
};