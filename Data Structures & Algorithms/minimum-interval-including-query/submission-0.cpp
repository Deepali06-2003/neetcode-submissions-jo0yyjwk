class Solution {
public:


    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        int n = queries.size();
        vector<int>res(n , -1);

        vector<pair<int, int>>q;
        for(int i =0;i<n;i++)q.push_back({queries[i] , i});

        sort(q.begin(), q.end());
        sort(intervals.begin(), intervals.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int j =0;
        for(int i =0;i<n;i++){
            int query = q[i].first;
            int idx = q[i].second;

            while(j<intervals.size() && intervals[j][0] <= query){
                pq.push({ intervals[j][1]-intervals[j][0]+1 , intervals[j][1] });
                j++;
            }

            while(!pq.empty() && query > pq.top().second ) pq.pop();

            if(!pq.empty()) res[idx] = pq.top().first;
        }
        return res;
    }
};
