class Solution {
public:

bool dfs(vector<vector<int>>adj , vector<bool>& visited , int i , int y){

    visited[i] = true;
    for(auto j : adj[i]){
        if(!visited[j]){
            if(!dfs(adj , visited , j, i))return false;
        }
        else if(y != j)return false;
    }
    return true;
}

    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool>visited(n , false);
        if(!dfs(adj , visited , 0, -1)) return false;

        for(int i=0;i<n;i++){
            if(visited[i] == false)return false;
        }

        return true;
    }
};
