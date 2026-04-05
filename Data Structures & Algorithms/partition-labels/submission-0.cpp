class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        vector<int>index(26, -1);
        for(int i =0;i<n;i++){
            index[s[i]-'a'] = i;
        }

        vector<int>res;

        int i =0;
        while(i<n){
            int last = index[s[i]-'a'];

            for(int j= i+1; j<=last ;j++){
                if( index[s[j]-'a'] > last){
                    last = index[s[j]-'a'];
                }
            } 
            int l = last - i+1;
            res.push_back(l);
            i = last+1;
        }
        return res;
    }
};
