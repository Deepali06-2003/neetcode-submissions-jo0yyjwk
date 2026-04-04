class Solution {
public:
int helper(vector<int>& nums ,vector<vector<int>>& dp, int l , int h){

    if(l>h)return 0;
    if(dp[l][h] != -1)return dp[l][h];

    int m = INT_MIN;
    for(int i = l;i<=h;i++){
        int x = nums[i]*nums[l-1]*nums[h+1];
        x = x + helper(nums, dp , l,i-1) + helper(nums , dp , i+1, h);

        m = max(m , x);
    }
    return dp[l][h] = m;
}
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return helper(nums , dp , 1 , n);
    }
};
