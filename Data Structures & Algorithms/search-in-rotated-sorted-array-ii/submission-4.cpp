class Solution {
public:

//     bool Ispresent(vector<int> &A, int target, int start, int end){
//         int mid1 = (start+end)/2;
//         while(start<=end){
//             if(A[mid1]==target){
//                 return true;
//             }
//             else if(A[mid1] > target){
//                 end = mid1-1;
//             }
//             else{
//                 start = mid1+1;
//             }
//             mid1 = (start+end)/2;
//         }
//         return false;
//     }

//     bool search(vector<int>& nums, int target) {
//         int n = nums.size();
//         int s = 0; 
//         int e = n-1;
//         int mid = (e+s)/2;

//         while(s<e){

//             if(nums[mid] > nums[e]){
//                 s = mid+1;
//             }

//             else if(nums[mid] < nums[e]){
//                 e = mid;
//             }
//             else{
//                 e--;
//             }
//             mid = (s+e)/2;
//         }

//         int ans = s;

//         if(Ispresent(nums, target, 0, mid)){
//             return true;
//         }
//         else if(Ispresent(nums, target, s, n-1)){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }

       bool search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            // Found target
            if(nums[mid] == target) {
                return true;
            }

            // Cannot determine which side is sorted
            if(nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }

            // Left half is sorted
            else if(nums[left] <= nums[mid]) {

                // Is target inside left sorted half?
                if(nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

            // Right half is sorted
            else {

                // Is target inside right sorted half?
                if(nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};



