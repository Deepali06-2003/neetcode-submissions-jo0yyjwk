class Solution {
public:

bool helper(string&s1 , string&s2 , string&s3 , int n , int m , int l , vector<vector<int>>& dp , int i , int j){

    if(i == n && j == m && (i+j)==l)return true;
    if((i+j)>=l)return false;

    if(dp[i][j]!=-1)return dp[i][j];

    bool ans = false;
    if(s1[i] == s3[i+j]) ans = helper(s1 , s2 , s3 , n , m , l , dp , i+1 , j);

    if(ans) return dp[i][j]=true;

    if(s2[j] == s3[i+j]) ans = helper(s1 , s2 , s3 , n , m , l , dp , i , j+1);

    return dp[i][j] = ans;
}
    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.size() , m = s2.size(), l = s3.size();

        if((n+m) != l) return false;
        vector<vector<int>> dp(n+1 , vector<int>(m+1, -1));

        return helper(s1 , s2 , s3 , n , m , l , dp, 0 , 0);
    }
};
