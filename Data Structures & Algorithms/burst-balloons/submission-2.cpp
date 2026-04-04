class Solution {
public:

    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>>dp(n+2, vector<int>(n+2, 0));

        for(int l =n;l>=1;l--){
            for(int r =1;r<=n;r++){
                if(l>r)continue;

                int ans = INT_MIN;
                for(int i = l;i<=r;i++){
                    int c = nums[i] * nums[l-1] * nums[r+1];
                    c = c + dp[l][i-1] + dp[i+1][r];

                    ans = max(ans , c);
                }
                dp[l][r] = ans;
            }
        }
        return dp[1][n];
    }
};


