class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int , int>s;
        vector<int>res;

        for(int i = 0;i<nums.size();i++){

            int x = target - nums[i];

            if (s.find(x) != s.end()) {
                res.push_back(s[x]);  // index of complement
                res.push_back(i);              // current index
                return res;
            }
        s[nums[i]] = i;
        }
        return res;
    }
};
