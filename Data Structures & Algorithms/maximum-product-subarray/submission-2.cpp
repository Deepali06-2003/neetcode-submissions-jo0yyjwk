class Solution {
public:
    int maxProduct(vector<int>& nums) {
     int n = nums.size();

     int ans = nums[0];
     int max_e = nums[0], min_e = nums[0];

     for(int i =1;i<nums.size();i++){
        int a = nums[i]*max_e;
        int b = nums[i]*min_e;

        max_e = max({b , a, nums[i]});
        min_e = min({a , b , nums[i]});

        ans = max(ans , max_e);
     }

     return ans;
    }
};
