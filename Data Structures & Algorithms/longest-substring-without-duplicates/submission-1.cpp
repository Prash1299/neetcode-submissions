// class Solution {
// public:

//     bool check(int count[]){
//         for(int i=0; i<26; i++){
//             if(count[i]>=2){
//                 return true;
//             }
//         }
//         return false;
//     }

//     int lengthOfLongestSubstring(string s) {

//         if(s.length()==1){
//             return 1;
//         }

//         int windowsize = 1;
//         int ans = 0;
//         int count[26] = {0};
//         int i = 0;

//         while(i < windowsize && windowsize <= s.length()){
//             char ch = s[i];
//             int index = ch-'a';
//             count[index]++;
//             i++;

//             if(check(count)){
//                 ans = windowsize-1;
//                 // count[s[i]]++;
//                 count[s[i-windowsize]]--;
//             }
//             else{
//                 windowsize++;
//                 // ans = windowsize;
//             }
//         }

//         while(i<s.length()){
//             char ch = s[i];
//             int index1 = ch-'a';
//             count[index1]++;

//             i++;

//             if(check(count)){
//                 ans = windowsize-1;
//                 // count[s[i]]++;
//                 count[s[i-windowsize]]--;
//             }
//             else{
//                 windowsize++;
//                 // ans = windowsize;
//             }
    
//         }
//         return ans;

//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1); // covers full ASCII, not just a-z
        int left = 0, ans = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];
            if (lastSeen[ch] >= left) {
                left = lastSeen[ch] + 1;   // jump left past the duplicate
            }
            lastSeen[ch] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
