class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n%2!=0)return false;

        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }

            else{
                
                
                if(st.empty()){
                    st.push(s[i]);
                }
                
                else{
                    char x = st.top();
                    if((s[i]==')' && x=='(') || (s[i]=='}' && x=='{') || (s[i]==']' && x=='['))st.pop();
                    else return false;
                }
            }
        }
        if(st.empty())return true;
        return false;
    }
};
