class Solution {
public:

    void solve(vector<int>& nums, int target,int index, vector<int> &ds, vector<vector<int>> &ans){
        //base case
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        if(index >= nums.size() || target < 0){
            return;
        }

        int n = nums.size();

        //include

        int element = nums[index];
        ds.push_back(element);
        solve(nums, target - element, index, ds, ans);
        ds.pop_back();

        //exclude
        solve(nums, target, index+1, ds, ans);
        
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int index = 0;
        solve(nums, target, index, ds, ans);
        return ans;
    }
};