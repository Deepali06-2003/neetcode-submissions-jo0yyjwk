class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        if(n != m)return false;
        unordered_map<char, int>st_s;
        unordered_map<char, int>st_t;

        for(char c : s)st_s[c]++;

        for(char c : t)st_t[c]++;

        return (st_s == st_t);
    }
};
