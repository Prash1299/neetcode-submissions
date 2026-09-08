class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int mid = (left+right)/2;

        while(left <= right){
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                right = mid -1;
            }
            else{
                left = mid + 1;
            }
            mid = (left+right)/2;
        }

        return left;
    }
};