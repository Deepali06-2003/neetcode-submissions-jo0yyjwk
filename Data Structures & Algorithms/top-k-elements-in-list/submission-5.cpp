class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    
      

         unordered_map<int,int> mp;
    for(int x : nums) mp[x]++;

    vector<vector<int>> freq(nums.size() + 1);

    for(auto &p : mp){
        freq[p.second].push_back(p.first);
    }

    vector<int> res;

    for(int i = nums.size(); i >= 0; i--){
        for(int x : freq[i]){
            res.push_back(x);
            if(res.size() == k)
                return res;
        }
    }

    return res;
    }
};
