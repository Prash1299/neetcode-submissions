class Solution {
public:

    int solve(vector<int>& nums, int index, int n, int prev, vector<vector<int>> &dp){
        //base case
        if(index >= n){
            return 0;
        }

        if(dp[index][prev+1] != -1){
            return dp[index][prev+1];
        }

        //exclude
        int exclude = solve(nums, index+1, n, prev, dp);

        //include

        int include = 0;

        if(prev == -1 || nums[index] > nums[prev]){
            include = 1 + solve(nums, index+1, n, index, dp);
        }

        return dp[index][prev+1] = max(include, exclude);

    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, 0, n, prev, dp);
    }
};
