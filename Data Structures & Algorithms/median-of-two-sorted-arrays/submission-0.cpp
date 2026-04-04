class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> res(n+m);

        int i = 0 , j=0, k=0;
        
        while(i<n && j<m){
            if(nums1[i]<= nums2[j]){
                res[k] = nums1[i];
                k++;
                i++;
            }
            else{
                res[k] = nums2[j];
                k++;
                j++;
            }
        }
        while(i<n){
            res[k] = nums1[i];
            k++;
            i++;
        }

        while(j<m){
            res[k]= nums2[j];
            k++;
            j++;
        }

        double ans =0;
        if((n+m)%2!=0){
            ans = res[(n+m)/2];
        }
        else{
            //cout<<res[(n+m-1)/2]<<' '<<res[ (n+m)/2];
            ans = (double)(res[(n+m-1)/2] + res[ (n+m)/2 ])/2;
        }
        return ans;
    }
};
