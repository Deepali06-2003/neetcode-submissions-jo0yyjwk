class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())return false;
        
        unordered_map<int, int>map;

        for(int i : s){
            map[i]++;
        }

        for(int i : t){
            if(map[i]==0 || map.count(i)==0)return false;
            map[i]--;
        }
        return true;
    }
};
