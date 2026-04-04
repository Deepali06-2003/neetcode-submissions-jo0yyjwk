class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int area = 0;


        for(int i = 0; i <= n; i++){
            int curr = (i == n ? 0 : heights[i]);

            while(!st.empty() && curr < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();

                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;

                area = max(area, h * width);
            }
            st.push(i);
        }
        return area;   
    }
};
