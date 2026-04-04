class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)q.push({i, j});
            }
        }

        vector<int>dx ={0, 0, 1, -1};
        vector<int>dy = {1 , -1 , 0 , 0};

        while(!q.empty()){
            
            pair<int, int>t = q.front();
            q.pop();

            for(int j=0;j<4;j++){
                int nx = t.first + dx[j];
                int ny = t.second + dy[j];

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==INT_MAX){
                    grid[nx][ny]= grid[t.first][t.second]+1;
                    q.push({nx, ny});
                }
            }
        }

    }
};
