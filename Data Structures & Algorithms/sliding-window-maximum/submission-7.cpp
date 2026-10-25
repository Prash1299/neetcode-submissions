class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // Stores indices
        vector<int> ans;

        for (int right = 0; right < nums.size(); right++) {

            // Remove indices outside the current window
            while (!dq.empty() && dq.front() <= right - k) {
                dq.pop_front();
            }

            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(right);

            // Record maximum once the first window is complete
            if (right >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};

