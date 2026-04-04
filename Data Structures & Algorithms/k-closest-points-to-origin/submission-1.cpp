class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res;
        int n = points.size();
        vector<pair<int, pair<int, int>>>arr;

        for(int i =0;i<n;i++){
            int x = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            arr.push_back({x , {points[i][0], points[i][1]} });
        }
        sort(arr.begin(), arr.end());
        for(int i =0;i<k;i++){
            res.push_back({arr[i].second.first, arr[i].second.second});
        }
        return res;
    }
};
