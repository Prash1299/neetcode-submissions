class Solution {
public:
    int countSubstrings(string s) {

        int n = s.length();

        vector<vector<bool>> dp(n,vector<bool>(n, false));

        int count = 0;

        for(int left = n - 1; left >= 0; left--) {

            for(int right = left; right < n; right++) {

                if(s[left] == s[right]) {

                    if(right - left <= 1) {
                        dp[left][right] = true;
                    }
                    else {
                        dp[left][right] =
                            dp[left + 1][right - 1];
                    }
                }

                if(dp[left][right]) {
                    count++;
                }
            }
        }

        return count;
    }
};
