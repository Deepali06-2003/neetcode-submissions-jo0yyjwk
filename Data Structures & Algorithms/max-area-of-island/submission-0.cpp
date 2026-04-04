class Solution {
public:
void helper(vector<vector<int>>& grid, int n , int m , int i , int j , int& curr_a){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0)return;

    curr_a++;
    grid[i][j]=0;

    helper(grid, n,m ,i+1 , j ,curr_a);
    helper(grid, n,m ,i-1 , j ,curr_a);
    helper(grid, n,m ,i , j+1 ,curr_a);
    helper(grid, n,m ,i , j-1 ,curr_a);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans=0;

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){

                if(grid[i][j]==1){
                    int curr_a=0;
                    helper(grid , n , m , i , j, curr_a);
                    ans = max(ans , curr_a);
                }
            }
        }return ans;
    }
};
