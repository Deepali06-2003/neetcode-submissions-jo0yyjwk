class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        vector<int>res(2,-1);
        unordered_map<int, int>map;

        for(int i=0;i<n;i++){
            int x = target-numbers[i];

            if(map.find(x)!=map.end()){
                res[0]= map[x];
                res[1]= i+1;
                return res;
            }
            map[numbers[i]] = i+1;
        }
        return res;
    }
};
