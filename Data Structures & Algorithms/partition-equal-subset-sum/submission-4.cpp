class Solution {
public:

    bool solve(vector<int>& nums, int index, int target, vector<vector<int>>& dp){
        //base case
        if(target == 0){
            return true;
        }

        if(index >= nums.size() || target < 0){
            return false;
        }

        if(dp[index][target] != -1){
            return dp[index][target];
        }

        //exclude
        bool exclude = solve(nums, index+1, target, dp);

        bool include = solve(nums, index+1, target - nums[index], dp);

        return dp[index][target] = include || exclude;

    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums){
            sum = sum + x;
        }

        if(sum%2 != 0){
            return false;
        }

        int target = sum/2;

        vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, -1));

        return solve(nums, 0, target, dp);
    }
};
