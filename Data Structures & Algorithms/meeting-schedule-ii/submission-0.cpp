/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        int n = intervals.size();

        if(n == 0) return 0;

        vector<int> start, end;

        for(auto it : intervals) {
            start.push_back(it.start);
            end.push_back(it.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int left = 0;
        int right = 0;

        int cnt = 0;
        int maxi = 0;

        while(left < n) {

            if(start[left] < end[right]) {
                cnt++;
                maxi = max(maxi, cnt);
                left++;
            }
            else {
                cnt--;
                right++;
            }
        }

        return maxi;
    }
};
