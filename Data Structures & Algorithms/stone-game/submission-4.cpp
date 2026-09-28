class Solution {
public:

    int solve(vector<int>& piles, int i, int j, vector<vector<int>> &dp) {

        if(i == j){
            return piles[i];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // Take first pile
        int takeFirst = piles[i] - solve(piles, i + 1, j, dp);

        // Take last pile
        int takeLast = piles[j] - solve(piles, i, j - 1, dp);

        return dp[i][j] = max(takeFirst, takeLast);
    }

    bool stoneGame(vector<int>& piles) {

        vector<vector<int>> dp(piles.size()+1, vector<int>(piles.size()+1, -1));

        int difference = solve(piles, 0, piles.size() - 1, dp);

        return difference > 0;
    }
};