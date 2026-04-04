class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>one(n ,-1);
        vector<int>zero(m,-1);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    one[i]=0;
                    zero[j]=0;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(one[i]==0 || zero[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
