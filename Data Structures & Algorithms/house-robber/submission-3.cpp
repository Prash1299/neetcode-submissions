class Solution {
public:
    int solve(vector<int>& nums, int index, int n, vector<int> &dp){
        //base case
        if (index >= n){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int ans = 0;

        int left = solve(nums, index+2, n, dp) + nums[index];
        int right = solve(nums, index+1, n, dp);

        return dp[index] = max(left, right);

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(nums, 0, n, dp);
    }
};
