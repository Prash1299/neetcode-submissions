class Solution {
public:

    void solve(vector<int>& nums, int target,int index, vector<int> &ds, vector<vector<int>> &ans){
        //base case
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        int n = nums.size();

        for(int i = index; i<n; i++){
            if(nums[i] > target){
                continue;
            }

            ds.push_back(nums[i]);
            solve(nums, target - nums[i], i, ds, ans);
            //backtrack
            ds.pop_back();
        }

        // solve(nums, target, index+1, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int index = 0;
        solve(nums, target, index, ds, ans);
        return ans;
    }
};
