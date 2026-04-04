class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        int mi = prices[0];
        for(int i =1 ;i< prices.size();i++){

            mi = min(mi , prices[i]);

            ans = max(ans , prices[i]- mi);
            if(ans<0)ans =0;

        }

        return ans;
    }
};
