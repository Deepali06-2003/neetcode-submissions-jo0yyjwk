class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;

        unordered_map<string, vector<string>>mp;
        for(string x : strs){
            string y = x;
            sort(y.begin(), y.end());
            mp[y].push_back(x);
        }

        for(auto i: mp){
            res.push_back(i.second);
        }
        return res;
    }
};
