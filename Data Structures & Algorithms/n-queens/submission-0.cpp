class Solution {
public:
bool isSafe(vector<string>board, int n, int r, int c){

    int row = r, col =c;

    while(r>=0 && c>=0){
        if(board[r][c]=='Q')return false;
        r--; c--;
    }
    r= row, c= col;
    while(c>=0){
        if(board[r][c]=='Q')return false;
        c--;
    }
    r= row, c= col;
    while(r<n && c>=0){
        if(board[r][c]=='Q')return false;
        r++; c--;
    }return true;
}
void solve(vector<vector<string>>& ans, vector<string>& board, int n, int c){
    if(c==n){
        ans.push_back(board);
        return;
    }

    for(int r=0;r<n;r++){
        if(isSafe(board, n, r, c)){
            board[r][c]='Q';
            solve(ans, board, n, c+1);
            board[r][c]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans ;
        vector<string>board(n);

        string s(n , '.');
        for(int i=0;i<n;i++)board[i]=s;

        solve(ans , board , n , 0);
        return ans;
    }
};
