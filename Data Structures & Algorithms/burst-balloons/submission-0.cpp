class Solution {
public:
int helper(vector<int>& nums ){

    if(nums.size() == 2)return 0;
    int ans =0;
    for(int i = 1 ; i<nums.size()-1;i++){
        int x = nums[i-1]*nums[i]*nums[i+1];

        vector<int> newNums = nums;
        newNums.erase(newNums.begin() + i);
        x = x+helper(newNums);
        ans = max(ans , x);
    }
    return ans;
}

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        if(n==0)return 0;
        if(n==1)return nums[0];
        
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        return helper(nums);
    }
};


