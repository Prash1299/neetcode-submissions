class Solution {
public:

    int solve(int amount, vector<int>& coins, int index, vector<vector<int>>& dp){
        //base case
        if(amount == 0){
            return 1;
        }

        if(index >= coins.size() || amount < 0){
            return 0;
        }

        if(dp[index][amount] != -1){
            return dp[index][amount];
        }

        int ans = 0;

        for(int i = index; i<coins.size(); i++){
            ans = ans + solve(amount - coins[i], coins, i, dp);
        }

        return dp[index][amount] = ans;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        return solve(amount, coins, 0, dp);
    }
};
