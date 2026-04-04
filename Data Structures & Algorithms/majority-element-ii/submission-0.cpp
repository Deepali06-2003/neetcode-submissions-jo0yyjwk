class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int>res;
        unordered_map<int, int>map;

        for(int i =0;i<nums.size();i++){
            map[nums[i]]++;
        }

        for(auto ptr:map){
            if(ptr.second > nums.size()/3){
                res.push_back(ptr.first);
            }
        }return res;
    }
};