class Solution {
public:
void helper(vector<int>& nums, int target,vector<vector<int>>& res, vector<int>curr, int start){
    if(target==0){
        res.push_back(curr);
        return;
    }
    if(target<0 ||start == nums.size())return;
    
    curr.push_back(nums[start]);
    helper(nums, target-nums[start], res, curr, start);
    curr.pop_back();
    helper(nums, target, res, curr, start+1);
    

}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>curr;

        helper(nums , target , res, curr, 0);
        return res;
    }
};
