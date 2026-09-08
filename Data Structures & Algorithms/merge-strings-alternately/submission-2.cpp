class Solution {
public:

    string mergeAlternately(string word1, string word2) {
        string s = "";

        int i = 0;
        int j = 0;

        while(i < word1.length() && j < word2.length()){
            s = s + word1[i];
            s = s + word2[j];
            i++;
            j++;
        }

        while(j<word2.length()){
            s = s+word2[j];
            j++;
        }

        while(i<word1.length()){
            s = s+word1[i];
            i++;
        }

        return s;
    }
};