class Solution {
public:
bool isSafe(vector<string>& board , int c , int r){

    int row = r , col = c;

    while(r>=0 && c>=0){
        if(board[r][c] == 'Q')return false;
        r--; c--;
    }
    r = row , c = col;
    while(c>=0){
        if(board[r][c] == 'Q')return false;
        c--;
    }
    r = row , c = col;
    while(r<board.size() && c>=0){
        if(board[r][c] == 'Q')return false;
        c--; r++;
    }

    return true;
}
void solve(vector<string>& board ,vector<vector<string>>& ans, int n , int col ){

    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int i =0;i<n;i++){
        if(isSafe(board , col , i)){
            board[i][col] = 'Q';
            solve(board , ans , n , col+1);
            board[i][col] = '.';
        }
    }

}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);

        string s(n,'.');
        for(int i=0;i<n;i++)board[i]=s;

        solve(board , ans , n , 0);
        return ans;
    }
};
