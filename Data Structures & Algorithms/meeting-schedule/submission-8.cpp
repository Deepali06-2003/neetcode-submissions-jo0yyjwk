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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n =intervals.size();
        if(n == 0)return true;

        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) {
            return x.start < y.start;
        });

        
        int e = intervals[0].end;

        for(int i=1;i<n;i++){
            if( intervals[i].start < e) return false;

            e = intervals[i].end;
          
        }
        return true;
        
    }
};
