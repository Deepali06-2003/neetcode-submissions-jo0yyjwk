class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
       vector<int>l(n , 0);
       vector<int>h(n , 0);
       
       l[0] = height[0];
        h[n-1] = height[n-1];

       for(int i =1 ;i<n ;i++){
        l[i] = max(l[i-1] , height[i]);
       }
       for(int i = n-2 ;i>=0 ;i--){
        h[i] = max(h[i+1] , height[i]);
       }

       int ans =0;
       for(int i =0 ;i<n;i++){
        ans = ans+ min(l[i] , h[i])- height[i];
       }

       return ans;

    }
};
