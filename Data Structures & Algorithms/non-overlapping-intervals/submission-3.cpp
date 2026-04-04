class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0 || n==1)return 0;
        int ans=0;

        sort(intervals.begin(), intervals.end());
        int s = intervals[0][0], e = intervals[0][1];

        for(int i =1;i<n;i++){
            if( intervals[i][0]<e ){
                //overlappingalignas
                ans++;
                e = min(e, intervals[i][1]);
            }
            else{
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }return ans;
    }
};
