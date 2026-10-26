class Solution {
public:

    int solve(vector<int>& nums, int index, vector<int>& dp){

        if(index >= nums.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int exclude = solve(nums, index+1, dp);
        int include = nums[index] + solve(nums, index+2, dp);

        return dp[index] = max(include, exclude);
    }

    int rob(vector<int>& nums) {
        int index = 0;
        vector<int> dp(nums.size()+1, -1);
        int output = solve(nums, index, dp);
        return output;
    }
};
