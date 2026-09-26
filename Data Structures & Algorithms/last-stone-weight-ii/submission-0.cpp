class Solution {
public:

    int solve(vector<int>& stones, int index, int currSum, int target, vector<vector<int>>& dp){

        //base case
        if(index >= stones.size()){
            return currSum;
        }

        if(dp[index][currSum] != -1){
            return dp[index][currSum];
        }

        //exclude
        int exclude = solve(stones, index+1, currSum, target, dp);

        //include
        int include = 0;
        if(currSum + stones[index] <= target){
            include = solve(stones, index+1, currSum + stones[index], target, dp);
        }

        return dp[index][currSum] = max(include, exclude);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int x : stones){
            sum = sum + x;
        }

        int target = sum/2;

        vector<vector<int>> dp(stones.size(), vector<int>(sum, -1));

        int closet = solve(stones, 0, 0, target, dp);

        return sum - 2 * closet;
    }
};