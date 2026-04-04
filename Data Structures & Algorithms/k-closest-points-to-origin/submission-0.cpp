class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;

        vector<pair<long long , pair<int , int> >>arr;

        for( auto & ptr: points){
            long long d = (1LL* ptr[0]*ptr[0]) + (1LL*ptr[1]*ptr[1]);
            arr.push_back({d, {ptr[0], ptr[1] }});
        }

        sort(arr.begin(), arr.end());
        for(int i=0;i<k;i++){
            res.push_back({arr[i].second.first, arr[i].second.second});
        }

        return res;

    }
};
