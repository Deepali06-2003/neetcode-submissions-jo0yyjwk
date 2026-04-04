class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int s=0;
        for(int i=0;i<n;i++)s= s+nums[i];

        if((s+target)<0 || (s+target)%2!=0)return 0;

        int x = (s+target)/2;

        vector<vector<int>>dp(n+1, vector<int>(x+1, 0));

        for(int i=0;i<=n;i++)dp[i][0]=1;

        for(int i=1;i<=n;i++){
            for(int j =0;j<=x;j++){

                if(nums[i-1]>j)dp[i][j]=dp[i-1][j];
                else dp[i][j]= dp[i-1][j] +dp[i-1][j-nums[i-1]];
            }
        }return dp[n][x];
    }
};
