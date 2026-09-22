class Solution {
public:

    int solve(vector<int>& cost, int n, int index, vector<int> &dp){
        ///base case
        if(index == n-1){
            return cost[index];
        }

        if(index >= n){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int left = cost[index] + solve(cost, n, index+1, dp);
        int right = cost[index] + solve(cost, n, index+2, dp);

        dp[index] = min(left, right);

        return dp[index];

    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        vector<int> dp(n+1, -1);
        // start from either 0 and 1 index
        int index_0 = 0;
        int index_1 = 1;
        return min(solve(cost, n, index_0, dp), solve(cost, n, index_1, dp));
        
    }
};