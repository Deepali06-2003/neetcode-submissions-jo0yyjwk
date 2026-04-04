class Solution {
public:
    bool isValid(string s) {
        
        int n = s.size();
        stack<char>st;

        for(char c : s){

            if(c == '(' || c=='{' || c=='[')st.push(c);
            else{
                if(st.empty())return false;
                char x = st.top();
                if( (x=='(' && c==')') || (x=='[' && c==']') || (x=='{' && c=='}') ){
                    
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!st.empty())return false;
        return true;

    }
};
