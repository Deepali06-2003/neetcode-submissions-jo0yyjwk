class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();

        int i=0;
        while(i<n){
            int curr = nums[i];
            if(nums[i]<n && nums[i] != nums[curr])swap(nums[i], nums[curr]);
            else i++;
        }

        for(int j=0;j<n;j++){
            if(nums[j]!=j)return j;
        }return i;
    }
};
