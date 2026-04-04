class Solution {
public:
bool dfs(vector<vector<int>>& adj , stack<int>& st, vector<int>& state, int x){
    state[x]=1;

    for(auto j : adj[x]){
        if(state[j] == 1)return true;
        if(state[j] == 0){
            if(dfs(adj, st, state, j))return true;
        }
    }

    st.push(x);
    state[x]=2;
    return false;
}
    string foreignDictionary(vector<string>& words) {
        
        vector<bool>present(26, false);
        for(string w : words){
            for(char c: w){
                present[c-'a'] = true;
            }
        }

        vector<vector<int>>adj(26);
        for(int i=0;i<words.size()-1;i++){

            string x = words[i], y = words[i+1];
            int l=0;
            
            while(l<x.size() && l<y.size()){
                if(x[l] != y[l]){
                    adj[x[l] - 'a'].push_back(y[l] - 'a');
                    break;
                }l++;
            }
            if(l == y.size() && x.size()>y.size())return "";
        }

        vector<int> state(26, 0);  // 0=unvisited,1=visiting,2=done
        stack<int> st;
        for(int i=0;i<26;i++){
            if(present[i]==true && state[i]==0){
                if(dfs(adj , st , state , i)) return "";
            }
        }

        string ans="";
        while(!st.empty()){
            ans = ans+ char(st.top()+'a');
            st.pop();
        }
        return ans;

    }
};
