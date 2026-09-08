class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> A;
        int n = nums.size();
        int k = (n/3) + 1;

        unordered_map <int, int> mp;  // value -> frequency

        for(int i=0; i<n ; i++){
            mp[nums[i]]++;
        }

        // int maxi=INT_MIN;
        // for(int i=0; i<n; i++){
        //     if(maxi < nums[i]){
        //         maxi = nums[i];
        //     }
        // }

        // int minii = INT_MAX;;
        // for(int i=0; i<n ; i++){
        //     if(minii > nums[i]){
        //         minii = nums[i];
        //     }
        // }

        for(auto x : mp) {

            if(x.second >= k) {
                A.push_back(x.first);
            }
        }

        return A;


    }
};