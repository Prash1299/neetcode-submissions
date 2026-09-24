class Solution {
public:

    bool solve(vector<int>& nums, int index, int target, vector<int> &dp){
        if(target == 0){
            return true;
        }

        if(target < 0){
            return false;
        }

        if(dp[target] != -1){
            return dp[target];
        }

        for(int i = index; i<nums.size(); i++){
            if(solve(nums, i+1, target-nums[i], dp)){
                return dp[target] = true;
            }
        }

        return dp[target] = false;

    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum = sum + nums[i];
        }

        if(sum%2 != 0){
            return false;
        }

        int target = sum/2;

        vector<int> dp(target+1, -1);

        return solve(nums, 0, target, dp);
    }
};
