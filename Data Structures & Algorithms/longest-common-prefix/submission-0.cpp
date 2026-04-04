class Solution {
public:
string helper(string s1 , string s2){
    if(s1.empty()|| s2.empty())return "";

    int i = 0, j=0;
    string curr= "";
    while(i<s1.size() && j<s2.size()){
        if(s1[i]==s2[j]){
            curr.push_back(s1[i]);
            i++;
            j++;
        }
        else return curr;
    }return curr;
}
    string longestCommonPrefix(vector<string>& strs) {
        string s1 = strs[0];
        for(int i =1;i<strs.size();i++){
            s1 = helper(strs[i], s1);
        }
        return s1;
    }
};