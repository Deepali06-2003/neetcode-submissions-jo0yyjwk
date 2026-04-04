class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string , vector<string>>mp;
        for(string w : strs){
            string s =w;
            sort(s.begin(), s.end());

            mp[s].push_back(w);
        }
        vector<vector<string>>res;
        for(auto j : mp){
            res.push_back(j.second);
        }
        return res;
    }
};
