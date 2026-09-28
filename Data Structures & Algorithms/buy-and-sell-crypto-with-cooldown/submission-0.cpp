class Solution {
public:

    int solve(vector<int>& prices, int index, int buy, vector<vector<int>> &dp){
        if(index >= prices.size()){
            return 0;
        }

        int profit = 0;

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        if(buy){
            profit = max((-prices[index] + solve(prices, index+1, 0, dp)), (solve(prices, index+1, 1, dp)));
        }

        else{
            profit = max((+prices[index] + solve(prices, index+2, 1, dp)), (solve(prices, index+1, 0, dp)));
        }

        return dp[index][buy] = profit;

    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
        return solve(prices, 0, 1, dp);
    }
};
