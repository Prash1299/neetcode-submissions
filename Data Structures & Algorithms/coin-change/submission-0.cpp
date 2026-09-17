class Solution {
public:

    int solve(vector<int>& coins, int amount, vector<int>& dp){
        int n = coins.size();
        if(amount == 0){
            return 0;
        }

        if(amount < 0){
            return INT_MAX;
        }

        int mini = INT_MAX;

        if(dp[amount] != -1){
            return dp[amount];
        }

        for(int i=0; i<n; i++){
            int ans = solve(coins, amount - coins[i], dp);
            if(ans != INT_MAX){
                mini = min(mini, 1+ans);
            }
        }

        dp[amount] = mini;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);

        int ans = solve(coins, amount, dp);

        if(ans == INT_MAX){
            return -1;
        }

        return ans;
    }
};