class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = 0;
        int s = 0;
        int size = nums.size();
        int e = size-1;
        int mid = s + (e-s)/2;

        while (s < e){
            if(nums[mid] > nums[e]){
                s = mid +1;
            }
            else {
                e =mid;
            }
            mid = s + (e-s)/2;
        }
        pivot = mid;

        int END = nums[size-1];
        
        if(nums[pivot] <= target && END >= target){
            return TARGET(nums, target, pivot, size-1);
        }

        else {
            return TARGET(nums, target, 0, pivot-1);
        }
        
    }

    int TARGET(vector<int>& nums, int target, int start, int end){
        int mid1 = (start+end)/2;
        while(start<=end){
            if(nums[mid1] == target){
                return mid1;
            }
            else if(target > nums[mid1]){
                start = mid1+1;
            }
            else{
                end = mid1-1;
            }
            mid1 = (start+end)/2;
        }
        return -1;
    }
};
