class Solution {
public:

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st) {
    vis[node] = 1;

    for (auto neigh : adj[node]) {
        if (!vis[neigh]) {
            
            dfs(neigh, adj, vis, st);
        }
    }

    st.push(node);
}

    int countComponents(int n, vector<vector<int>>& edges) {

        vector<int>adj[n];
        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        stack<int>st;
        int ans=0;
        vector<int>vis(n , 0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i , adj, vis , st);
                ans++;
            } 
        }
        

        return ans;
    }
};
