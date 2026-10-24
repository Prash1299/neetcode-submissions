class Solution {
public:

    string longestPalindrome(string s) {

        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxi = 1;
        int start = 0;

        for(int left = n - 1; left >= 0; left--) {

            for(int right = left; right < n; right++) {

                if(s[left] == s[right]) {

                    if(right - left <= 1) {
                        dp[left][right] = true;
                    }
                    else {
                        dp[left][right] = dp[left + 1][right - 1];
                    }
                }

                if(dp[left][right]) {

                    int length = right - left + 1;

                    if(length > maxi) {
                        maxi = length;
                        start = left;
                    }
                }
            }
        }

        return s.substr(start, maxi);
    }
};
