class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_p=0;

        for(int i =1;i<prices.size();i++){
            int p = prices[i]- prices[i-1];
            if(p>0)max_p = max_p+p;
        }return max_p;
    }
};