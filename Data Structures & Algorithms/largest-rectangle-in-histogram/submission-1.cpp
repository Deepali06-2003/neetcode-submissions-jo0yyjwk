class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int area = 0;


       for(int i =0;i<n;i++){
        while(!st.empty() && heights[i] < heights[st.top()]){
            int x = st.top();
            st.pop();

            int nx = i;
            int pr = (st.empty())?-1 :st.top();

            area = max(area , (nx-pr-1)*heights[x]);
        }
        st.push(i);
       }  

       while(!st.empty() ){
            int x = st.top();
            st.pop();

            int nx = n;
            int pr = (st.empty())?-1 :st.top();

            area = max(area , (nx-pr-1)*heights[x]);
        }
        return area;
    }
};
