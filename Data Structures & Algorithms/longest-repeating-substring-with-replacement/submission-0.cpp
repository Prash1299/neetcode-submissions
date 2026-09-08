// class Solution {
// public:
//     int characterReplacement(string s, int k) {

//         int n = s.length();

//         vector<int> count(26);

//         for(int i=0; i<n; i++){
//             int index = s[i]-'A';
//             count[index]++;
//         }

//         int maxi = 0;
//         int ans = 0;
//         int i;

//         for(i = 0; i < 26; i++){
//             if(count[i] > maxi){
//                 maxi = count[i];
//                 ans = i;
//             }
//         }

//         char ch = i + 'A';  // character which is largest in count in string

//         int l = 0;

//         while(l<k){
//             for(int m=0; m<n; m++){
//                 if(s[m]!=ch){
//                     s[m] = ch;
//                     l++;
//                 }
//             }
//         }

//         int countx = 0;
//         for(int j=0; j<n; j++){
//             if(s[j]==ch){
//                 countx++;
//             }
//         }

//         return countx;

        
        
//     }
// };


class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.length();

        vector<int> count(26, 0);

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            // Add current character
            count[s[right] - 'A']++;

            // Maximum frequency inside current window
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            // Number of characters we need to replace
            int windowLength = right - left + 1;
            int replacements = windowLength - maxFreq;

            // Window is invalid
            while (replacements > k) {

                count[s[left] - 'A']--;
                left++;

                windowLength = right - left + 1;
                replacements = windowLength - maxFreq;
            }

            ans = max(ans, windowLength);
        }

        return ans;
    }
};
