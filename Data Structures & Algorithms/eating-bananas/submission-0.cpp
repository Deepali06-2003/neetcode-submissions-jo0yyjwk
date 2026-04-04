class Solution {
public:
bool helper(vector<int>& piles, int h , int m){
    int c=0;
    for(int i = 0 ; i<piles.size();i++){

        c = c+ ceil((double) piles[i]/m);
    }
    return c<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int hi = *max_element(piles.begin() , piles.end());
        
        while(l< hi){
            int m = (l+ hi)/2;

            if(helper(piles , h , m)){
                hi = m;
            }
            else{
                l =m+1;
            }
        }
        return hi;

    }
};
