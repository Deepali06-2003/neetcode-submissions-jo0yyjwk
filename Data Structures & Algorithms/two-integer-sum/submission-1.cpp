class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>res(2,-1);
        unordered_map<int, int>map;
        for(int i =0;i<n;i++){
            int x= target-nums[i];

            if(map.find(x)!= map.end()){
                res[0]= map[x];
                res[1]=i;
                return res;
            }
            else map[nums[i]]=i;
        }return res;
    }
};
