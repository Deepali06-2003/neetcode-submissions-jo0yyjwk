class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;

        unordered_set<int>set;
        for(int i:nums)set.insert(i);

        int l = 1;

        for(auto i: set){
            if(set.find(i-1)== set.end()){
                int c=1, x =i;
                while(set.find(x+1)!=set.end()){
                    c++;
                    x=x+1;
                }
                l = max(l, c);
            }
        }
        return l;
    }
};
