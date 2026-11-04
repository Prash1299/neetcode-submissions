
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int n = s.length();

        vector<int> str(128, -1);
        int maxi = 0;

        while (right < n) {
            char ch = s[right];
            int index = ch;

            if (str[index] >= left) {
                left = str[index] + 1;
            }

            str[index] = right;

            maxi = max(maxi, right - left + 1);

            right++;
        }

        return maxi;
    }
};

