class Solution {
public:

    int solve(vector<int>& nums, int left, int right, vector<vector<int>>& dp) {

        // No balloon between left and right
        if(left + 1 == right) {
            return 0;
        }

        if(dp[left][right] != -1){
            return dp[left][right];
        }

        int ans = 0;

        // Choose k as the LAST balloon to burst
        for(int k = left + 1; k < right; k++) {

            int coins = nums[left] * nums[k] * nums[right] + solve(nums, left, k, dp) + solve(nums, k, right, dp);

            ans = max(ans, coins);
        }

        return dp[left][right] = ans;
    }

    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));

        return solve(nums, 0, nums.size() - 1, dp);
    }
};