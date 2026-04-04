class Solution {
public:
double helper(double x, int n){
    if(n==0)return 1.0;

    double half = helper(x, n/2);
    if(n%2==0)return half*half;
    return half*half*x;
}
    double myPow(double x, int n) {
        
        if(n==0)return 1.0;
        if(n==1)return x;

        if(n<0){
            n = abs(n);
            return 1.0/helper(x, n);
        }
        return helper(x, n);
    }
};
