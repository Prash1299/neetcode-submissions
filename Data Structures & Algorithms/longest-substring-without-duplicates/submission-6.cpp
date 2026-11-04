class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int n = s.length();
        int maxi = 0;

        unordered_map<char, int> mp;

        while(right < n){
            mp[s[right]]++;

            while(mp[s[right]] > 1){
                mp[s[left]]--;
                left++;
            }

            maxi = max(maxi, right-left + 1);
            right++;
        }

        return maxi;
    }
};
