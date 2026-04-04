class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        if(m > n)return "";

        vector<int>freq(256, 0);
        for(int i =0;i<m;i++)freq[t[i]]++;

        int l =0, r=0;
        int s_i = -1, le = INT_MAX;
        int c=0;

        while(r<n){
            if(freq[s[r]] > 0)c++;
            freq[s[r]]--;
            r++;


            while(c == m){
                if((r-l)< le){
                    s_i = l;
                    le = r-l;
                }

                
                freq[s[l]]++;
                if(freq[s[l]]>0)c--;
                l++;   
            }
        }
        if(le == INT_MAX)return "";
        return s.substr(s_i, le);
    }
};
