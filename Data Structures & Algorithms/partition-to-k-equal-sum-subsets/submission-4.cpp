class Solution {
public:

    bool solve(vector<int>& nums, int k, int target,
               int index, vector<bool>& used, int currSum) {

        // We have successfully formed k-1 subsets.
        // The remaining elements automatically form the last subset.
        if(k == 1) {
            return true;
        }

        // Current subset is complete
        if(currSum == target) {
            return solve(nums, k-1, target, 0, used, 0);
        }

        for(int i = index; i < nums.size(); i++) {

            // Already used
            if(used[i]) {
                continue;
            }

            // Don't exceed target
            if(currSum + nums[i] > target) {
                continue;
            }

            // Choose
            used[i] = true;

            // Explore
            if(solve(nums, k, target, i+1,
                     used, currSum + nums[i])) {
                return true;
            }

            // Backtrack
            used[i] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int n = nums.size();

        int sum = 0;

        for(int x : nums) {
            sum += x;
        }

        if(sum % k != 0) {
            return false;
        }

        int target = sum / k;

        vector<bool> used(nums.size(), false);

        return solve(nums, k, target, 0, used, 0);
    }
};