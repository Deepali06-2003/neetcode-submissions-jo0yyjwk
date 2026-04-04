class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int c=0, x=nums[0];

        for(int i=0;i<n;i++){
            if(c==0){
                x=nums[i];
                c=1;
            }
            if(nums[i]==x){
                c++;
            }
            else{
                c--;
            }
        }return x;
    }
};