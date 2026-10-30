class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxlim = 0;
        
        for(int i = 0; i<nums.size(); i++){

            if(i > maxlim){
                return false;
            }

            maxlim = max(maxlim, i+nums[i]);
            
        }

        return true;
    }
};
