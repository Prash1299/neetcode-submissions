class Solution {
public:

    int solve(int amount, vector<int>& coins, int index, int currSum, vector<vector<int>>& dp){
        if(index >= coins.size()){
            if(currSum == amount){
                return 1;
            }
            return 0;
        }

        if(dp[index][currSum] != -1){
            return dp[index][currSum];
        }

        int exclude = solve(amount, coins, index+1, currSum, dp);

        int include = 0;
        if(currSum + coins[index] <= amount){
            include = solve(amount, coins, index, currSum+coins[index], dp);
        }

        return dp[index][currSum] = include + exclude;
    }

    int change(int amount, vector<int>& coins) {
        int index = 0;
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int ans = solve(amount, coins, index, 0, dp);
        return ans;
    }
};
