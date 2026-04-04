class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(string st : strs){
            s = s+ to_string(st.size())+'#'+st;
        }
        return s;
    }

    vector<string> decode(string s) {
        
        vector<string>res;
        int i =0;
        while(i< s.size()){

            int j = i;
            while(s[j]!='#') j++;
            int l = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j+1, l));
            i = j+l +1;
        }
        return res;
    }
};
