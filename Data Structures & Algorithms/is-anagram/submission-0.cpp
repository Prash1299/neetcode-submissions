class Solution {
public:
    bool isAnagram(string s, string t) {
        // int i=0;
        // int j=0;
        if(s.length()!=t.length()){
            return false;
        }

        int count1[26]={0};
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            int index = ch-'a';
            count1[index]++;
        }

        int count2[26]={0};
        for(int j=0; j<t.length(); j++){
            char ch1 = t[j];
            int index2 = ch1-'a';
            count2[index2]++;
        }

        for(int k = 0; k<26; k++){
            if(count1[k]!=count2[k]){
                return false;
            }
        }

        return true;

    }
};
