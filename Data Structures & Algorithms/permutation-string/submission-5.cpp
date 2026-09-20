class Solution {
public:

    bool compare(vector<int> arr1, vector<int> arr2){

        for(int i=0; i<26; i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        vector<int> arr1(26);
        vector<int> arr2(26);

        for(int i=0; i<n1; i++){
            char ch = s1[i];
            int val = ch - 'a';
            arr1[val]++;
        }

        int windowsize = n1;
        int j = 0;

        while(j<windowsize && j<n2){
            char ch = s2[j];
            int val = ch - 'a';
            arr2[val]++;
            j++;
        }

        if(compare(arr1, arr2)){
            return true;
        }

        while(j<n2){
            char ch = s2[j];
            int val = ch - 'a';
            arr2[val]++;

            char oldchar = s2[j-windowsize];
            int oldval = oldchar - 'a';
            arr2[oldval]--;

            j++;

            if(compare(arr1, arr2)){
                return true;
            }
        }

        return false;

    }
};
