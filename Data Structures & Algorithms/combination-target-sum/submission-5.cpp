class Solution {
public:

    void solve(vector<int>& nums, int target, vector<vector<int>> &ans, vector<int> &ds, int index){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i=index; i<nums.size(); i++){

            if(target < nums[i]){
                continue;
            }

            ds.push_back(nums[i]);
            solve(nums, target - nums[i], ans, ds, i);
            ds.pop_back();
            
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int index = 0;
        solve(nums, target, ans, ds, index);
        return ans;
    }
};
