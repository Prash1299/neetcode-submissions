class Solution {
public:
    bool solve(string &s, unordered_set<string> &dict,
               int index, vector<int> &dp) {

        // Base case: Entire string is segmented
        if (index == s.length()) {
            return true;
        }

        // Already calculated
        if (dp[index] != -1) {
            return dp[index];
        }

        // Try all substrings starting at index
        for (int i = index; i < s.length(); i++) {

            string word = s.substr(index, i - index + 1);

            if (dict.count(word)) {

                if (solve(s, dict, i + 1, dp)) {
                    return dp[index] = true;
                }
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(
            wordDict.begin(), wordDict.end()
        );

        vector<int> dp(s.length(), -1);

        return solve(s, dict, 0, dp);
    }
};