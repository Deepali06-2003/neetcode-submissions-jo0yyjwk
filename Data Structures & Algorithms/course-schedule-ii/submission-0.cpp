class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[v];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int>indegree(v, 0);
        for(int i=0;i<v;i++){
            for(auto j : adj[i]){
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int>topo;
        while(!q.empty()){

            int x = q.front();
            q.pop();

            topo.push_back(x);

            for(auto j : adj[x]){
                indegree[j]--;
                if(indegree[j]==0)q.push(j);
            }
        }
        if(v == topo.size())return topo;
        return {};
    }
};
