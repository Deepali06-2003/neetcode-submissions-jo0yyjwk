class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int l=0, r=0;
        int max_len =0, max_freq=0;
        vector<int>map(26, 0);

        while(r<s.size()){
            map[s[r]-'A']++;
            max_freq = max(max_freq, map[s[r]-'A']);

            if((r-l+1)-max_freq > k){
                map[s[l]-'A']--;
                l++;
            }

            if((r-l+1)-max_freq <=k){
                max_len = max(max_len , r-l+1);
            }
            r++;
        }
        return max_len;
    }
};
