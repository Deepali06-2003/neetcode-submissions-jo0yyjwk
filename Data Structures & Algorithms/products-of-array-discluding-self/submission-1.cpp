class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        int p=1, r=1;
        
        vector<int>dp(n, 1);

        for(int i=0;i<n;i++){
            dp[i]=p;
            p = p*nums[i];
        }
        for(int i=n-1;i>=0;i--){
            dp[i]= dp[i]*r;
            r = r*nums[i];
        }return dp;
    }
};
