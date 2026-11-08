class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int, int>> meetings;
        int n = intervals.size();

        for(int i = 0; i<n; i++){
            meetings.push_back({intervals[i][1], intervals[i][0]});
        }

        sort(meetings.begin(), meetings.end());
        int count = 1;
        int endtime = meetings[0].first;

        for(int i = 1; i<n; i++){
            if(meetings[i].second >= endtime){
                count++;
                endtime = meetings[i].first;
            }
        }

        return n-count;
    }
};
