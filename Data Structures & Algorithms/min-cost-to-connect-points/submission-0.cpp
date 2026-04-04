class Solution {
public:

int primsAlgo(int V, vector<vector<pair<int,int>>>& adj){

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> visited(V, 0);

    pq.push({0, 0});
    int sum = 0;

    while(!pq.empty()){

        auto t = pq.top();
        pq.pop();

        int w = t.first;
        int node = t.second;

        if(visited[node])
            continue;

        visited[node] = 1;
        sum += w;

        for(auto &j : adj[node]){
            int ed_n = j.first;
            int wt = j.second;

            if(!visited[ed_n])
                pq.push({wt, ed_n});
        }
    }

    return sum;
}

int minCostConnectPoints(vector<vector<int>>& points) {

    int V = points.size();
    vector<vector<pair<int,int>>> adj(V);

    for(int i = 0; i < V - 1; i++){
        for(int j = i + 1; j < V; j++){

            int dist = abs(points[i][0] - points[j][0]) +
                       abs(points[i][1] - points[j][1]);

            adj[i].push_back({j, dist});
            adj[j].push_back({i, dist});
        }
    }

    return primsAlgo(V, adj);
}
};