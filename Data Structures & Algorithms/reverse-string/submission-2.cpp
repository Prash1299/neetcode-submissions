class Solution {
private: 

    char tolowercheck(char ch){
        if(ch > 'a' && ch < 'z'){
            return ch;
        }
        else{
            char temp = ch-'A'+'a';
            return temp;
        }
    }

public:

    void reverseString(vector<char>& s) {
        int st = 0;
        int e = s.size()-1;
        while(tolowercheck(st) <= tolowercheck(e)){
            swap(s[st], s[e]);
            st++;
            e--;
        }
        
    }
};