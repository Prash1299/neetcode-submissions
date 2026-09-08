class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        vector<int> prefix(n);

        prefix[0] = nums[0];

        for(int i=1; i<n ; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        if(prefix[n-1] < target){
            return 0;
        }

        int left = 0;
        int right = 0; 
        int result = INT_MAX;

        while(right<n){

            int sum = 0;

            if(left==0){
                sum = prefix[right];
            }

            else{
                sum = prefix[right]-prefix[left-1];
            }

            if(sum>=target){
                result = min(result, right-left+1);
                left++;
            }

            else{
                right++;
            }
            
        }
        return result;
        
    }
};