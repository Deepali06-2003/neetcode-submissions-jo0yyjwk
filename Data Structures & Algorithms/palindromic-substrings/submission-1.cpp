class Solution {
public:
void isPalindrome(string s, int l , int h, int& ans){
    while(l>=0 && h<s.size() && s[l]==s[h]){
        l--;
        h++;
        ans++;
    }
    
}
    int countSubstrings(string s) {
        int n = s.size();

        int ans=0;

        for(int i =0;i<n;i++){
            isPalindrome(s ,i , i , ans);
            isPalindrome(s, i, i+1, ans);
        }
        return ans;
    }
};
