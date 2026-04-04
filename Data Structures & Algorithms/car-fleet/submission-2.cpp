class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pair;

        for (int i = 0; i < n; i++) {
            pair.push_back({position[i], speed[i]});
        }

        sort(pair.rbegin(), pair.rend());
        for (int i = 0; i < n; i++) {
            cout<< pair[i].first<<" "<<pair[i].second<<endl;
        }

        int fleets = 1;
        double ans = (double)(target - pair[0].first)/pair[0].second ;

        for (int i = 1; i < n; i++) {
            double timeTotravel = (double)(target - pair[i].first) / pair[i].second;

            if(timeTotravel > ans){
                fleets++;
                ans = timeTotravel;
            }
        }
        return fleets;
    }
};
