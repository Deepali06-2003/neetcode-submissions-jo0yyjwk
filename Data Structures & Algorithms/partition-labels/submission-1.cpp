class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>res;

        vector<int>freq(26, -1);
        for(int i =0;i<s.size();i++) freq[s[i]-'a'] = i;

        int i =0;
        while(i<s.size()){
            int l_idx = freq[s[i]-'a'];

            for(int j = i+1;j<=l_idx; j++){
                if( freq[s[j]-'a'] > l_idx) l_idx = freq[s[j]-'a'];
            }

            res.push_back(l_idx-i+1);
            i = l_idx+1;
        }
        return res;
    }
};
