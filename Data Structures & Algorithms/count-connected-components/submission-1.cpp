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
        for(int i=0;i< edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
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
