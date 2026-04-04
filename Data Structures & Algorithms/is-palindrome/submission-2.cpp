class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0);

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int l =0, h =s.size()-1;
        while(l<h){
            if(!isalnum(s[l])){
                l++;
                continue;
            }
            if(!isalnum(s[h])){
                h--;
                continue;
            }
            if(s[l]!=s[h])return false;
            else{
                l++;
                h--;
            }
        }return true;

    }
};
