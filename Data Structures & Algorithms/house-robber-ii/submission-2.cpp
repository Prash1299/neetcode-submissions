class Solution {
public:
    int solve(vector<int>& nums, int index, int n, vector<vector<int>> &dp,int first_house){
        //base case
        if (index >= n){
            return 0;
        }

        if(dp[index][first_house] != -1){
            return dp[index][first_house];
        }
        if(index==n-1){
            if(first_house==0){
                return nums[index];
            }
            else{
                return 0;
            }
        }

        int ans = 0;
        if(index==0){
        int left = solve(nums, index+2, n, dp,1) + nums[index];
        int right = solve(nums, index+1, n, dp,first_house);
        return dp[index][first_house] = max(left, right);
        }
        int left = solve(nums, index+2, n, dp,first_house) + nums[index];
        int right = solve(nums, index+1, n, dp,first_house);

        return dp[index][first_house] = max(left, right);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int first_house=0;
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(nums,0,n,dp,0);
        
    }
};
