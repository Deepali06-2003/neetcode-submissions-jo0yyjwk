class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        vector<pair<int, int>>arr(n);
        for(int i =0;i<n;i++){
            arr[i].first = position[i];
            arr[i].second = speed[i];
        }

        sort(arr.rbegin(), arr.rend());
        int ans = 1;
        double x = (double)(target-arr[0].first)/arr[0].second;

        for(auto j : arr){
            double y = (double)(target-j.first)/j.second;

            if(y > x){
                ans++;
                x = y;
            }
        }

        return ans;
    }
};
