class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int left =0;
        // int right = nums.size()-1;
        // int current = 0;
        // while(left<right){
        //     current = nums[left] + nums[right];
        //     if(current == target){
        //         return {left, right};
        //     } 
        //     else if(current<target){
        //         left = left + 1;
        //     }
        //     else{
        //         right = right - 1;
        //     }
        // }
        // return {};


        unordered_map<int, int> seen;  // value -> index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.count(complement)) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        return {};  // no solution found
    }
};
