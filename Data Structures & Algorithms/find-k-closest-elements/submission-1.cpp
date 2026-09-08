// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         vector<int> A = {};

//         int n = arr.size();

//         if(n==k || n==0){
//             return nums;
//         }

//         int left = 0;
//         int right = n-1;
//         int mid = (left + right)/2;
//         int index = -1;

//         while(left <= right){
//             if(nums[mid] < x){
//                 left = mid+1;
//             }
//             else if(nums[mid] == x){
//                 index = mid;
//             }
//             else{
//                 right = mid - 1;
//             }

//             mid = (left+right)/2;
//         }

//         index = left;

//         for(int i=index; i<n+1; i++){
//             nums[i] = nums[i+1];
//         }

//         nums[left] = x;

//         int diffsum = 0;
//         int diff = 0;

//         int left = index - k;
//         int right = index;
//         int mini = INT_MAX;

//         while(right < index + k){

//             for(int i = left; i<right; i++){
//                 diffsum = diffsum + abs(nums[i] - x);
//             }
//             if(diffsum < mini){
//                 mini = diffsum;
//             }

//             right++;
//             left++
//         }
        

//     }
// };

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        vector<int> A;

        int n = arr.size();

        if(n == k) {
            return arr;
        }

        // --------------------------------
        // 1. Binary search for insertion position of x
        // --------------------------------

        int left = 0;
        int right = n - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(arr[mid] < x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        // left = first position where arr[left] >= x
        int index = left;


        // --------------------------------
        // 2. Check possible k-sized windows
        // --------------------------------

        int start = max(0, index - k);
        int end = min(index, n - k);

        int mini = INT_MAX;
        int bestStart = 0;

        for(int i = start; i <= end; i++) {

            int diffsum = 0;

            for(int j = i; j < i + k; j++) {
                diffsum += abs(arr[j] - x);
            }

            if(diffsum < mini) {
                mini = diffsum;
                bestStart = i;
            }
        }


        // --------------------------------
        // 3. Store answer
        // --------------------------------

        for(int i = bestStart; i < bestStart + k; i++) {
            A.push_back(arr[i]);
        }

        return A;
    }
};