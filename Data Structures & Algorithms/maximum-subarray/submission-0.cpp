class Solution {
public:

    int solve(vector<int> &nums, int index, int sum, int maxi){
        if(index >= nums.size()){
            return maxi;
        }

        int include = sum + nums[index];

        int exclude = nums[index];

        int currSum = max(include, exclude);
        maxi = max(maxi, currSum);

        return solve(nums, index+1, currSum, maxi);

    }

    int maxSubArray(vector<int>& nums) {
        int index = 0;
        int maxi = INT_MIN;
        int sum = 0;
        return solve(nums, index, sum, maxi);
    }
};
