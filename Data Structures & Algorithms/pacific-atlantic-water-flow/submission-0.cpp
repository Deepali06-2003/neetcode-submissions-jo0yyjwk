class Solution {
public:
void bfs(vector<vector<int>>& heights , vector<vector<bool>>& visited , queue<pair<int, int>>& q){
    int n = heights.size();
    int m = heights[0].size();

    vector<int>dx = {0 , 0, 1, -1};
    vector<int>dy = {1, -1, 0 , 0};

    while(!q.empty()){

        pair<int , int> temp = q.front();
        q.pop();

        for(int j=0;j<4;j++){
            int nx = temp.first + dx[j];
            int ny = temp.second + dy[j];

            if(nx>=0 && ny>=0 && nx<n && ny<m && visited[nx][ny]==false && heights[temp.first][temp.second]<= heights[nx][ny] ){
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }

    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>res;

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        queue<pair<int, int>>q_pac;
        queue<pair<int, int>>q_atl;

        for(int i=0;i<n;i++){
            q_pac.push({i, 0});
            pac[i][0]=true;
            q_atl.push({i, m-1});
            atl[i][m-1]=true;
        }

        for(int i=0;i<m;i++){
            q_pac.push({0, i});
            pac[0][i]=true;
            q_atl.push({n-1 , i});
            atl[n-1][i]=true;
        }

        bfs(heights, pac, q_pac);
        bfs(heights, atl , q_atl);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j]==true && atl[i][j]==true)res.push_back({i, j});
            }
        }

        return res; 
    }
};
