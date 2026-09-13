class Solution {
public:
        void backtrack(int index, vector<int>& nums, int remaining, vector<int>& current, vector<vector<int>>& result) {

            // Found a valid combination
            if (remaining == 0) {
                result.push_back(current);
                return;
            }

            // Try each number from index onwards
            for (int i = index; i < nums.size(); i++) {

                // Since nums is sorted,
                // all later numbers will also be too large
                if (nums[i] > remaining)
                    break;

                // Choose
                current.push_back(nums[i]);

                // Don't move to i+1 because
                // the same number can be reused
                backtrack(i,
                        nums,
                        remaining - nums[i],
                        current,
                        result);

                // Undo choice
                current.pop_back();
            }
        }

        vector<vector<int>> combinationSum(vector<int>& nums, int target) {

            sort(nums.begin(), nums.end());

            vector<vector<int>> result;
            vector<int> current;

            backtrack(0, nums, target, current, result);

            return result;
      
        }
};
