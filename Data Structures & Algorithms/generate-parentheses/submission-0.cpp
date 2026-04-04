class Solution {
public:
void helper(int n ,vector<string>& res , string curr , int open , int close){
    
    if(n== close){
        res.push_back(curr);
        return;
    }

    if(open < n){
        curr.push_back('(');
        helper(n , res , curr, open+1, close);
        curr.pop_back();
    }
    if(close < open){
        curr.push_back(')');
        helper(n , res , curr, open, close+1);
        curr.pop_back();
    }

}
    vector<string> generateParenthesis(int n) {

        vector<string>res;
        string curr;

        if(n==0)return res;

        helper(n , res , curr , 0,0);

        return res;
    }
};
