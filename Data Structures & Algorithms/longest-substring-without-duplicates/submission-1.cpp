class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int>m;
        int l =0;
        int ans=0;

        for(int r =0 ;r<s.size() ;r++){
            if(m.find(s[r]) != m.end()  && m[s[r]] >= l){
               l = m[s[r]] + 1;
            }
            m[s[r]] = r;
            ans = max(ans, r-l+1);

        }
        return ans;
    }
};
