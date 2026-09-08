class Solution {
public:

    bool valid (char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            return true;
        }
        else{
            return false;
        }
    } 

    char toLowercheck(char a){
        if((a>='a' && a<='z') || (a>='0' && a<='9')){
            return a;
        }
        else{
            char temp = a-'A'+'a';
            return temp;
        }
    }

    bool Checkpallindrome(string a){
        int s = 0;
        int e = a.length()-1;

        while(s<=e){
            if(a[s]!=a[e]){
                return false;
            }
            else{
                s++;
                e--;
            }
        }
        return true;
    }

    bool isPalindrome(string s) {

        // Remove the unnecessaery elements

        string u="";
        for(int j=0 ; j<s.length(); j++){
            if(valid(s[j])){
                u.push_back(s[j]);
            }
        }
        
        // Convert to lower case 

        for(int j=0; j<u.length(); j++){
            u[j] = toLowercheck(u[j]);
        }

        // Check pallindrome

        return Checkpallindrome(u);
    }
};