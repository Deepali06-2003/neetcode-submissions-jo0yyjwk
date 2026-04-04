class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int min_p = INT_MAX;
        for(int i =0;i<prices.size();i++){
            min_p = min(min_p , prices[i]);
            ans = max(ans , prices[i]-min_p);
        }
        return ans;
    }
};
