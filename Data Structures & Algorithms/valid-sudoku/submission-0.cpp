class Solution {
public:

bool isValidSub(vector<vector<char>>& board, int r, int c, int n,int m){
    set<int>st;
    for(int i=r;i<=n;i++){
        for(int j=c;j<=m;j++){
            if(board[i][j] == '.') continue;
            if(st.find(board[i][j]) != st.end())return false;
            st.insert(board[i][j]);
        }
    }
    return true;
}


    bool isValidSudoku(vector<vector<char>>& board) {
        set<int>st;
        
        for(int i=0;i<9;i++){
            st.clear();
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end())return false;
                st.insert(board[i][j]);
            }
        }
        for(int i=0;i<9;i++){
            st.clear();
            for(int j=0;j<9;j++){
                if(board[j][i] == '.') continue;
                if(st.find(board[j][i]) != st.end())return false;
                st.insert(board[j][i]);
            }
        }
        for(int sr =0;sr<9; sr=sr+3){
            for(int sc=0;sc<9;sc=sc+3){
                int er=sr+2, ec=sc+2;
                if(!isValidSub(board, sr, sc, er, ec)) return false;
            }
        }

        return true;
    }
};
