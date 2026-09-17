class Solution {
public:

    int solve(vector<int> &cost, int n){
        vector<int> dp(n+1);

        //base case
        dp[0] = cost[0];
        dp[1] = cost[1];

        //step 2
        for(int i=2; i<n; i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }

        return min(dp[n-1], dp[n-2]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost, n);
    }
};
