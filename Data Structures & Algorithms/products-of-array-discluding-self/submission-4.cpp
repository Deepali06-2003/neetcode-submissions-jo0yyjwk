class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int>res(nums.size(), 1);
        
        int lp =1 , rs =1;
        for(int i=0 ; i<nums.size();i++){
            res[i] = lp;
            lp = lp*nums[i];
            cout<<res[i]<<' ';
        }cout<<endl;
        for(int i = nums.size()-1;i>=0;i--){
            res[i]= res[i]*rs;
            rs = rs*nums[i];
            cout<<res[i]<<' ';
        }
        return res;
    }
};
