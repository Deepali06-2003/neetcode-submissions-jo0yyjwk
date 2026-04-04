class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_i =0;
        for(int i = 0 ; i<n;i++){
            if(i> max_i)return false;

            max_i = max(max_i , i+nums[i]);

        }
        return true;
    }
};
