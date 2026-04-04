class Solution {
public:
bool helper(vector<int>& piles, int h, int m){
    int x=0;
    for(int i =0;i<piles.size();i++){
        x = x+ (ceil)((double)piles[i]/m);
    }
    return x<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();


        int low = 1 , high = *max_element(piles.begin(), piles.end());

        while(low<high){
            int mid = (low+high)/2;

            if(helper(piles , h , mid)){
          
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        return high;
    }
};
