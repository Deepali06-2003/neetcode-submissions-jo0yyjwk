class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int>res(nums.size() , 1);
        int p =1 , s=1;

        for(int i =1 ;i<nums.size();i++){
            p = p* nums[i-1];

            res[i] = p;
        }
        for(int i = nums.size()-2 ;i>=0 ;i--){
            s = s* nums[i+1];
            res[i] = res[i]* s;
        }

        return res;

    }
};
