class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int m = prices[0];

        for(int i=1;i<prices.size();i++){

            m = min(m , prices[i]);
            ans = max(ans , prices[i]-m);
            if(ans<0)ans=0;
            
        }return ans;
    }
};
