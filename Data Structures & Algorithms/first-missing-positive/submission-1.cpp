class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n =nums.size();

        int i=0;
        while(i<n){
            if(nums[i]>0 && nums[i]<=n && nums[i] != nums[nums[i]-1]){
                int curr = nums[i]-1;
                swap(nums[i], nums[curr]);
            }
            else i++;
        }

        for(int j=0;j<n;j++){
            if(nums[j] != j+1)return j+1;
        }return i+1;
    }
};