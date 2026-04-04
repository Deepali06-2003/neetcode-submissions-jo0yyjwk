class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i =0;i<n-2;i++){
            
            int target = -nums[i];
            int j =i+1, k=n-1;
            
            if(i>0 && nums[i]==nums[i-1])continue;

            while(j<k){
                
                if((nums[j]+nums[k]) == target){
                    curr.clear();
                    curr.push_back(nums[i]);
                    curr.push_back(nums[j]);
                    curr.push_back(nums[k]);

                    j++;
                    k--;
                    
                    while(j<k && nums[j]== nums[j-1])j++;
                    while(j<k && nums[k]==nums[k+1])k--;

                    res.push_back(curr);
                }
                else if((nums[j]+nums[k]) > target)k--;
                else j++;
                
            }
        }return res;
        
    }
};
