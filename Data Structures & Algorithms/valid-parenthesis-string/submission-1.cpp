class Solution {
public:

    bool solve(string& s, int index, int count, vector<vector<int>>& dp) {

        if(count < 0) {
            return false;
        }

        if(index == s.length()) {
            return count == 0;
        }

        if(s[index] == '(') {
            return solve(s, index+1, count+1, dp);
        }

        if(s[index] == ')') {
            return solve(s, index+1, count-1, dp);
        }

        if(dp[index][count] != -1){
            return dp[index][count];
        }

        // '*' can represent three possibilities

        bool open = solve(s, index+1, count+1, dp);

        bool close = solve(s, index+1, count-1, dp);

        bool empty = solve(s, index+1, count, dp);

        return dp[index][count] = open || close || empty;
    }

    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solve(s, 0, 0, dp);
    }
};
