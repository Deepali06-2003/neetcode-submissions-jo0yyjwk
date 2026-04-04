class Solution {
public:

bool dfs(vector<vector<int>>& adj, vector<int>& vis, int x, int y) {

    if (x == y) return true;

    vis[x] = 1;

    for (int neigh : adj[x]) {
        if (!vis[neigh]) {
            if (dfs(adj, vis, neigh, y)) return true;
        }
    }
    return false;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
    int n = edges.size();
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n; i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        vector<int> vis(n + 1, 0);

        if (dfs(adj, vis, u, v))
            return edges[i];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return {};
    }
};


