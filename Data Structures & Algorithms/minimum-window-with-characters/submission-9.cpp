class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<int> window(128, 0);

        for(char c : t){
            need[c]++;
        }

        int left = 0;
        int right = 0;

        int have = 0;
        int required = 0;

        for(int i=0; i<128; i++){
            if(need[i] > 0){
                required++;
            }
        }

        int start = 0;
        int min_len = INT_MAX;

        while(right < s.length()){
            char ch = s[right];
            window[ch]++;

            if(need[ch] > 0 && window[ch] == need[ch]){
                have++;
            }

            while(have == required){
                if(right - left + 1 < min_len){
                    min_len = right - left + 1;
                    start = left;
                }

                char leftchar = s[left];
                window[leftchar]--;

                if(need[leftchar] > 0 && window[leftchar] < need[leftchar]){
                    have--;
                }

                left++;
            }

            right++;
        }

        if(min_len == INT_MAX){
            return "";
        }

        return s.substr(start, min_len);

    }
};
