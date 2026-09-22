class Solution {
public:
    int solve(vector<int>&cost,int idx,int n,vector<int>&dp){
        if(idx==n-1){
            return cost[idx];
        }
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        return dp[idx]=min(cost[idx]+solve(cost,idx+1,n,dp),cost[idx]+solve(cost,idx+2,n,dp));

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(solve(cost,1,n,dp),solve(cost,0,n,dp));
    }
};
