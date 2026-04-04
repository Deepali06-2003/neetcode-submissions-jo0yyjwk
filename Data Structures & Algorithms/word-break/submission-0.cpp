class Solution {
public:
bool helper(int i , unordered_set<string>& st, string& s, vector<int>& dp){
    
    if(s.size() == i)return true;
    if(st.find(s) != st.end() )return true;
    if(dp[i] != -1)return dp[i];

    for(int l = 1; l<=s.size()-i ; l++){
        string x = s.substr(i, l);

        if( (st.find(x)!=st.end()) && (helper(i+l,st,s, dp)) )return dp[i]=1;
    }
    return dp[i]=0;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string>st;
        for(string i : wordDict) st.insert(i);

        vector<int> dp(s.size(), -1);

        return helper(0 , st , s, dp);
    }
};
