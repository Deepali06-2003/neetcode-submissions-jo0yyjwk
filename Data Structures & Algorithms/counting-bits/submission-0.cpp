class Solution {
public:
int helper(int n){
    int c=0;
    while(n!=0){
        n = n&(n-1);
        c++;
    }return c;
}
    vector<int> countBits(int n) {
        vector<int>res(n+1, 0);

        res[0]=0;
        res[1]=1;
        for(int i=2;i<=n;i++){
            res[i] = helper(i);
        }return res;
    }
};
