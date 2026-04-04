class Solution {
public:
bool possible(vector<vector<int>>& grid , int n,vector<vector<bool>>& visited,  int i , int j, int t){
    if(i < 0 || i>= n || j<0 || j>=n || visited[i][j] == true || grid[i][j] > t)return false;

    visited[i][j]= true;
    if(i == n-1 && j == n-1)return true;

    vector<int>dx = {0, 0, 1, -1};
    vector<int>dy = {1, -1, 0, 0};

    for(int k =0;k<4;k++){
        int nx = i + dx[k];
        int ny = j + dy[k];

        if(possible(grid, n , visited, nx, ny , t)) return true;
    }
    return false;
    
}
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int l = grid[0][0], r = n*n-1;

        int ans = 0;

        while(l <= r){
            int m = (l+r)/2;
            vector<vector<bool>>visited(n , vector<bool>(n , false));

            if(possible(grid , n ,visited,  0 , 0, m)){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }

        return ans;
    }
};
