class Solution {
public:


unordered_map<string, vector<string>>adj;
vector<string>res;
int n_t =0;

bool dfs(string x , vector<string>& path){
   
    path.push_back(x);

    if(path.size() == n_t+1){
        res = path;
        return true;
    }

    vector<string>& to_city = adj[x];
    for(int i=0; i< to_city.size() ; i++){

        string y = to_city[i];

        to_city.erase(to_city.begin()+i);
        if(dfs(y , path)) return true;
        to_city.insert(to_city.begin()+i , y);

    }
    path.pop_back();
    return false;

}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n_t = tickets.size();   

        for(auto t : tickets){
            adj[t[0]].push_back(t[1]);
        }

        for(auto& e : adj){
            sort(begin(e.second) , end(e.second));
        }
        
        vector<string>path;
        dfs("JFK" , path);

        return res;
    }
};
