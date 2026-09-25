class Solution {
public:

    bool isPalindrome(string &s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }

    void solve(string &s, int index, vector<string>& output,
               vector<vector<string>>& ans) {

        // Base case
        if(index == s.length()) {
            ans.push_back(output);
            return;
        }

        // Try every possible substring starting from index
        for(int i = index; i < s.length(); i++) {

            // Check s[index...i]
            if(isPalindrome(s, index, i)) {

                // Choose
                output.push_back(s.substr(index, i-index+1));

                // Explore
                solve(s, i+1, output, ans);

                // Backtrack
                output.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> output;

        solve(s, 0, output, ans);

        return ans;
    }
};
