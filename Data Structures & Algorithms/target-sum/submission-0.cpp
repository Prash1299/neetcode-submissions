class Solution {
public:

    int solve(vector<int>& nums, int target, int index, int currSum, vector<vector<int>> &dp, int sum){
        //base case
        if(index == nums.size()){
            if(currSum == target){
                return 1;
            }

            return 0;
        }

        if(dp[index][currSum + sum] != -1){
            return dp[index][currSum + sum];
        }

        // add
        int add = solve(nums, target, index + 1, currSum + nums[index], dp, sum);

        // subtract
        int subtract = solve(nums, target, index + 1, currSum - nums[index], dp, sum);

        return dp[index][currSum + sum] = add + subtract;

    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
        }

        vector<vector<int>> dp(nums.size()+1, vector<int>(2*sum + 1, -1));
        return solve(nums, target, 0, 0, dp, sum);
    }
};
