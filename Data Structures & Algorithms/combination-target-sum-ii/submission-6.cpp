class Solution {
public:

    void solve(vector<int> &candidates, int target, int index, vector<int> &output, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(output);
            return;
        }

        for(int i = index; i<candidates.size(); i++){
            
            // Skip duplicate choices at the same level
            if(i > index && candidates[i] == candidates[i-1])
                continue;

            if(candidates[i] > target){
                continue;
            }

            output.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i+1, output, ans);
            output.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(candidates.begin(), candidates.end());

        int index = 0;
        solve(candidates, target, index, output, ans);

        return ans;
    }
};
