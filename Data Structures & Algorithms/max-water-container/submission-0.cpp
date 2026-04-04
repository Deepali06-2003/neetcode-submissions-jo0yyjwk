class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int area = -1;

        int l =0;
        int h = n-1;

        while(l<h){
            int length = min(heights[l], heights[h]);
            int breath = h-l;

            area = max(length*breath , area);

            if(heights[l] <= heights[h])l++;
            else h--;
        }return area;
    }
};
