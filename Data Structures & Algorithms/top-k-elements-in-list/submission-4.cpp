class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int>map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }

        vector<vector<int>>freq(n+1);
        for(auto ptr:map){
            freq[ptr.second].push_back(ptr.first);
        }

        vector<int>res;
        for(int i=n;i>=0;i--){
            for(int j :freq[i]){
                res.push_back(j);
                if(res.size()==k)return res;
            }
        }return res;
    }
};
