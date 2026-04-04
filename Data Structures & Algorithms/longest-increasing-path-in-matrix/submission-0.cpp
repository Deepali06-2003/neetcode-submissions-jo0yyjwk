class Solution {
public:

int helper(vector<vector<int>>& matrix ,vector<vector<int>>& dp ,int n , int m , int i , int j){
    
    if(dp[i][j]!= 0)return dp[i][j];

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int c=1;

    for(auto& d : dir){
        int nx = i+d[0];
        int ny = j+d[1];

        if(nx>=0 && nx<n && ny>=0 && ny<m && matrix[nx][ny] > matrix[i][j]){
            c = max(c , 1+helper(matrix , dp , n , m , nx , ny) );
        }
    }
    dp[i][j] = c;
    return c;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        int ans=0;

        vector<vector<int>>dp(n , vector<int>(m , 0));

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                ans = max(ans , helper(matrix ,dp, n , m , i, j));
            }
        }

        return ans;
    }
};

