class Solution {
public:

    void sortColors(vector<int>& nums) {
        vector<int> A;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                A.push_back(nums[i]);
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i]==1){
                A.push_back(nums[i]);
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i]==2){
                A.push_back(nums[i]);
            }
        }

        nums = A;
    }
};