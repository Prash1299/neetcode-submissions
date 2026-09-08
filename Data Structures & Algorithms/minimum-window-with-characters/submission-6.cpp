class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> count1(128, 0);
        vector<int> count2(128, 0);

        // Frequency of characters required from t
        for(int i = 0; i < t.length(); i++){
            count1[t[i]]++;
        }

        // Number of distinct characters in t
        int required = 0;

        for(int i = 0; i < 128; i++){
            if(count1[i] > 0){
                required++;
            }
        }

        int left = 0;
        int right = 0;

        // Number of distinct characters whose required
        // frequency has been satisfied
        int have = 0;

        int minilength = INT_MAX;
        int start = 0;

        while(right < s.length()){

            char ch = s[right];
            count2[ch]++;

            // We just satisfied the required frequency
            if(count1[ch] > 0 &&
               count1[ch] == count2[ch]){
                have++;
            }

            // Try to shrink the window
            while(required == have){

                if(right - left + 1 < minilength){
                    minilength = right - left + 1;
                    start = left;
                }

                char leftchar = s[left];
                count2[leftchar]--;

                // We lost a required character
                if(count1[leftchar] > 0 &&
                   count2[leftchar] < count1[leftchar]){
                    have--;
                }

                left++;
            }

            right++;
        }

        if(minilength == INT_MAX){
            return "";
        }

        return s.substr(start, minilength);
    }
};