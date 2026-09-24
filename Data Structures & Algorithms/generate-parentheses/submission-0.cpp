class Solution {
public:

    void solve(int n, int open, int close, vector<string>& ans, string output){
        if(open == n && close == n){
            ans.push_back(output);
            return;
        }

        //open
        if(open < n){
            output.push_back('(');
            solve(n, open+1, close, ans, output);
            output.pop_back();
        }

        //close
        if(close < open && close <= n){
            output.push_back(')');
            solve(n, open, close+1, ans, output);
            output.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        int open = 0;
        int close = 0;
        solve(n, open, close, ans, output);

        return ans;
    }
};
