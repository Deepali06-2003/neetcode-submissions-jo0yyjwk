class Solution {
public:
//b == 1 -> buy 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<int>> dp (n+1, vector<int>(2, 0));

        int ans = 0, mi = prices[0];
        for(int i =1;i<n;i++){
            mi = min(mi, prices[i]);
            ans = max(ans ,prices[i]-mi);
        }
        return ans;
    }
};
