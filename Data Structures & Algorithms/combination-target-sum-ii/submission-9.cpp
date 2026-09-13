class Solution {
public:

    void solve(vector<int> &candidates, int k, vector<int> &output, int i, vector<vector<int>> &result){
        if(i == candidates.size()){
            if(k == 0){
                result.push_back(output);
            }
            return;
        }

        // include
        if(k >= candidates[i]){
            output.push_back(candidates[i]);
            solve(candidates, k-candidates[i], output, i+1, result);
            output.pop_back();
        }

        int next = i + 1;
        while(next < candidates.size() &&
            candidates[next] == candidates[i]) {
            next++;
        }

        solve(candidates, k, output, next, result);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> output;
        int index = 0;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, output, index, result);
        return result;
    }
};
