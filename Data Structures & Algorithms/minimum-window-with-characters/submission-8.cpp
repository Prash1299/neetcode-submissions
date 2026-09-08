class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count1(128, 0);
        vector<int> count2(128, 0);

        for(int i=0; i<t.length(); i++){
            count1[t[i]]++;
        }

        int required = 0;  // no. of distinct characters in t

        for(int i=0; i < 128; i++){
            if(count1[i] > 0){
                required++;
            }
        }

        int left = 0;
        int right = 0;

        int have = 0;      // no. of characters that we have at point of time

        int minilength = INT_MAX;
        int start = 0;

        while(right < s.length()){

            char ch = s[right];
            count2[ch]++;

            if(count1[ch] > 0 && count1[ch] == count2[ch]){
                have++;
            }

        

            while(required == have){
                if(right-left+1 < minilength){
                    minilength = right-left+1;
                    start = left;
                }

                char leftchar = s[left];
                count2[leftchar]--;

                if(count1[leftchar] > 0 && count2[leftchar] < count1[leftchar]){
                    have--;
                }

                left++;
            }

            right++;
        }

        if(minilength == INT_MAX){
            return "";
        }
        else{
            return s.substr(start, minilength);
        }
    }
};

