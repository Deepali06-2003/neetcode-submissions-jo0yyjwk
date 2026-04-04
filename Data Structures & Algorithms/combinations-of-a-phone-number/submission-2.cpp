class Solution {
public:
unordered_map<int, vector<char>>mp;


void helper(string digits, vector<string>& res, string curr, int s){
 
    if(s == digits.size()){
        res.push_back(curr);
        return;
    }

    int x = digits[s]-'0';
    vector<char>str = mp[x];

    for(int i=0;i<str.size();i++){

        curr = curr+str[i];
        helper(digits, res, curr, s+1);
        curr.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.size()==0)return res;

        mp[2] = {'a','b','c'};
        mp[3] = {'d','e','f'};
        mp[4] = {'g','h','i'};
        mp[5] = {'j','k','l'};
        mp[6] = {'m','n','o'};
        mp[7] = {'p','q','r' ,'s'};
        mp[8] = {'t','u','v'};
        mp[9] = {'w','x','y','z'};

        string curr;
        helper(digits, res, curr, 0);
        return res;
    }
};
