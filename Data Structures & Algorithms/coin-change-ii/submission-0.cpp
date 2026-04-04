class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>>dp(n+1 , vector<int>(amount+1, 0));
        for(int i = 1;i<=n ;i++)dp[i][0] =1;
        

        for(int i=1;i<=n;i++){
            for(int j =1;j<=amount;j++){

                if(coins[i-1]>j)dp[i][j]= dp[i-1][j];
                else dp[i][j] = dp[i][j-coins[i-1]]+ dp[i-1][j];

                cout<<dp[i][j]<<' ';
            }
            cout<<endl;
        }

        if(dp[n][amount]==INT_MAX-1)return 0;
        return dp[n][amount];
    }
};
