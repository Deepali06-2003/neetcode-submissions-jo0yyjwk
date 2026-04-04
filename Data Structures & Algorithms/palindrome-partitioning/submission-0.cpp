class Solution {
public:

bool isPalindrome(string s, int l , int h){
    while(l<h){
        if(s[l]!=s[h])return false;
        l++; h--;
    }return true;
}

void helper(string s, vector<vector<string>>& res, vector<string>& curr, int start){

    if(start == s.size()){
        res.push_back(curr);
        return;
    }

    for(int i = start ;i<s.size();i++){

        if(isPalindrome(s, start , i)){
            curr.push_back(s.substr(start, i-start+1));
            helper(s , res , curr, i+1);
            curr.pop_back();
        }
    }

}


    vector<vector<string>> partition(string s) {
       
        vector<vector<string>>res;
        vector<string>curr;

        helper(s, res, curr, 0);
        return res;
        
    }
};
