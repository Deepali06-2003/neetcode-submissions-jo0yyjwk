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
        if(n==0)return 0;
        if(n==1)return 1;

        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) { return x.start < y.start; });

        int e = intervals[0].end ;
        vector<int>int_end;
        int_end.push_back(e);

        for(int i = 1 ; i<n;i++){
            
            int s = int_end.size();
            int flag =0;
            for(int j = 0 ;j<s ;j++){
                if(intervals[i].start >= int_end[j] ){
                    flag =1;
                    int_end[j] = max(int_end[j] , intervals[i].end );
                    break;
                }
            }
            if(flag == 0) int_end.push_back(intervals[i].end); 
        }
        return int_end.size();
        
    }
};
