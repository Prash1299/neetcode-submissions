class Solution {
public:

    int solve(vector<int> &nums, int index, int n, vector<int> &dp){
        //base case
        if(index >= n){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int rob = nums[index] + solve(nums, index+2, n, dp);
        int skip = 0 + solve(nums, index+1, n, dp);

        return dp[index] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        int index = 0;

        if(n == 1) {
            return nums[0];
        }

        vector<int> first_1, first_0;

        for(int i=0; i<n; i++){
            if(i!= n-1){
                first_1.push_back(nums[i]);
            }

            if(i!= 0){
                first_0.push_back(nums[i]);
            }
        }

        vector<int> dp1(n, -1);
        vector<int> dp0(n, -1);

        return max(solve(first_1, index, first_1.size(), dp1), solve(first_0, index, first_0.size(), dp0));
        

    }
};
