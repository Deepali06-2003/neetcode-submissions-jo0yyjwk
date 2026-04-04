#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.size();
        int l =0;
        int h = n-1;
        //s = tolower(s);


        while(l<h){
            if(!(s[l]>='a'&& s[l]<='z' ||s[l]>='A'&& s[l]<='Z'|| s[l]>='0'&& s[l]<='9')) {
                l++;
                continue;
            }
            if(!(s[h]>='a'&& s[h]<='z' ||s[h]>='A'&& s[h]<='Z'|| s[h]>='0'&& s[h]<='9')){
                h--;
                continue;
            }

            if(tolower(s[l]) != tolower(s[h])){
                return false;
            }
            else{
                l++;
                h--;
            }
        }
        return true;
    }
};
