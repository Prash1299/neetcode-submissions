// class Solution {
// public:
//     int maxArea(vector<int>& heights) {
//         int size = heights.size();
//         int area = 0;
//         int ans = 0;
//         int width = 0;
//         int left = 0;
//         int right = size-1;
//         while (left <= right){
//             int width = (right-left);
//             int area = min(heights[left], heights[right])*width;
//             ans = max(area, ans);
//             if(heights[right] > heights[left]){
//                 left++;
//             }
//             else{
//                 right--;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;

        while (left < right) {

            int h;
            if (height[left] < height[right])
                h = height[left];
            else
                h = height[right];

            int area = h * (right - left);

            if (area > ans)
                ans = area;

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return ans;
    }
};
