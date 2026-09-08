class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> prefix(n);

        prefix[0] = nums[0];

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        unordered_map <int, int> mp;

        mp[0] = 1;

        int ans = 0;
        int sum = 0;

        for(int i=0; i<n; i++){
            sum = prefix[i];
            ans = ans + mp[sum - k];
            mp[sum]++;
        }

        return ans;
    }
};