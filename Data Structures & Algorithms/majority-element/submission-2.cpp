class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        int k = n/2;

        for(int i=0; i<n; i++){
            if(mp[nums[i]] > k){
                return nums[i];
            }
        }

        return -1;
    }
};