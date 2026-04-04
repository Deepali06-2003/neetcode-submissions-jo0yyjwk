class Solution {
public:
void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>curr, int start){
   
    if(curr.size()==nums.size()){
        res.push_back(curr);
        return;
    }

    for(int i = 0 ;i<nums.size();i++){
        if(find(curr.begin(), curr.end(), nums[i])!= curr.end())continue;
        
        curr.push_back(nums[i]);
        helper(nums, res, curr, i+1);
        curr.pop_back();
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;

        helper(nums, res, curr, 0);
        return res;
    }
};
