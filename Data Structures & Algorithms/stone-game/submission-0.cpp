class Solution {
public:

    bool solve(vector<int>& piles, int i, int j, int score, bool aliceTurn, vector<vector<int>>& dp){
        //base case
        if(i > j){
            return score > 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(aliceTurn){
            bool first_A = solve(piles, i+1, j, score + piles[i], false, dp);
            bool last_A = solve(piles, i, j-1, score + piles[j], false, dp);
            return dp[i][j] = first_A || last_A;
        }

        bool first_B = solve(piles, i+1, j, score - piles[i], true, dp);
        bool last_B = solve(piles, i, j-1, score - piles[i], true, dp);
        return dp[i][j] = first_B || last_B;

    }

    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), -1));
        return solve(piles, 0, piles.size()-1, 0, true, dp);
    }
};