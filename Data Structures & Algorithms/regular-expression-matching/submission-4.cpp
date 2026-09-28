class Solution {
public:

    bool solve(string &s, string &p, int i, int j,
               vector<vector<int>>& dp) {

        // Both completely matched
        if(i < 0 && j < 0) {
            return true;
        }

        // Pattern exhausted but string remains
        if(j < 0) {
            return false;
        }

        // String exhausted
        if(i < 0) {
            while(j >= 0) {

                // Remaining pattern must be x*y*z*
                if(p[j] != '*') {
                    return false;
                }

                j -= 2;
            }

            return true;
        }

        // Already calculated
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters match or pattern has '.'
        if(s[i] == p[j] || p[j] == '.') {

            return dp[i][j] =
                solve(s, p, i-1, j-1, dp);
        }

        // '*'
        if(p[j] == '*') {

            // Case 1: '*' matches zero characters
            bool zero = solve(s, p, i, j-2, dp);

            // Case 2: '*' matches one or more characters
            bool oneOrMore = false;

            if(s[i] == p[j-1] || p[j-1] == '.') {

                oneOrMore =
                    solve(s, p, i-1, j, dp);
            }

            return dp[i][j] = zero || oneOrMore;
        }

        // No match
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        int n = s.length();
        int m = p.length();

        vector<vector<int>> dp(
            n,
            vector<int>(m, -1)
        );

        return solve(s, p, n-1, m-1, dp);
    }
};