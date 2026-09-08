class Solution {
public:

    bool Isequal(int count1[], int count2[]){
        for(int i=0; i<26; i++){
            if(count1[i]!=count2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        // for S1
        int count1[26] = {0};
        
        for(int i=0; i<s1.length(); i++){
            char ch = s1[i];
            int index = ch-'a';
            count1[index]++;
        }

        int windowsize = s1.length();
        int count2[26] = {0};
        int i = 0;

        while(i<windowsize && i<s2.length()){
            char ch = s2[i];
            int index = ch-'a';
            count2[index]++;
            i++;
        }

        if(Isequal(count1, count2)){
            return true;
        }

        while(i<s2.length()){
            char ch = s2[i];
            int index = ch-'a';
            count2[index]++;

            char oldchar = s2[i-windowsize];
            int index1 = oldchar - 'a';
            count2[index1]--;

            i++;

            if(Isequal(count1, count2)){
                return true;
            }

            
        }

        return false;
        
    }
};
