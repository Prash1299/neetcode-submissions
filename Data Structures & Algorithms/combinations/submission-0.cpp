class Solution {
public:
    
    void solve(int n, int k, vector<int> output, int start, vector<vector<int>> &ans){

        // We have selected k numbers
        if(output.size() == k) {
            ans.push_back(output);
            return;
        }

        for(int i = start; i <= n; i++) {

            // Choose
            output.push_back(i);

            // Explore
            solve(n, k, output, i + 1, ans);

            // Backtrack
            output.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;

        vector<int> output;
        int start = 1;

        solve(n, k, output, start, ans);

        return ans;
    }
};