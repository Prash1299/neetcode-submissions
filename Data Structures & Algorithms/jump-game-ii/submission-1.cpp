class Solution {
public:

    int solve(vector<int>& nums, int idx, int count, vector<vector<int>>& dp){

        if(idx >= nums.size()-1){
            return count;
        }

        if(dp[idx][count] != -1){
            return dp[idx][count];
        }

        int ans = INT_MAX;

        for(int i = 1; i <= nums[idx]; i++){
            ans = min(ans, solve(nums, idx + i, count+1, dp));
        }

        return dp[idx][count] = ans;
    }

    int jump(vector<int>& nums) {
        int idx = 0;
        int count = 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(nums, idx, count, dp);
    }
};
