class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        for(auto i : flights){
            adj[i[0]].push_back({i[1], i[2]});
        }
                //stop       node. dist
        queue<pair<int , pair<int, int>>>q;
        vector<int>dist(n , INT_MAX);

        dist[src]=0;
        q.push({0 , {src, 0} });


        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            int curr_s = temp.first;
            int curr_node = temp.second.first;
            int curr_dist = temp.second.second;

            if(curr_s > k)continue;

            for(auto j : adj[curr_node]){
                int n = j.first;
                int c = j.second;

                if( c+curr_dist < dist[n] && curr_s <= k){
                    dist[n] = c + curr_dist;
                    q.push({curr_s +1 , {n , c+ curr_dist } });
                }
            }
        }

        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};
