class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int , int>map;

        for(int i : nums){
            if( map.find(i) != map.end() ){
                return i;
            }
            map.insert({i , 1});
        }
        return 0;
    }
};
