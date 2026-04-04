class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;

        sort(nums.begin(), nums.end());
        int l = 1, c=0, l_s=INT_MIN;
        
        for(int i=0;i<n;i++){
            if(nums[i]-1 == l_s){
                c++;
                l_s = nums[i];
            }
            else{
                if(nums[i]!=l_s){
                    c=1;
                    l_s=nums[i];
                }
            }
            l = max(l, c);
        }return l;
    }
};
