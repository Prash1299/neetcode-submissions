
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;

        int n = intervals.size();

        if(n == 0) return ans;

        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        int endtime = intervals[0][1];

        for(int i = 1; i < n; i++) {

            if(intervals[i][0] <= endtime) {

                endtime = max(intervals[i][1], endtime);
                ans.back()[1] = endtime;

            }
            else {

                ans.push_back(intervals[i]);
                endtime = intervals[i][1];

            }
        }

        return ans;
    }
};
