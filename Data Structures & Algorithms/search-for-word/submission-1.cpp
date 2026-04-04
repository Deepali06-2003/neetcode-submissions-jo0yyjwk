class Solution {
public:
bool helper(vector<vector<char>>& board,int n , int m , int i , int j, string& word,int s){
    
    if(s == word.size())return true;
    
    if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[s])return false;
    
    
    char temp = board[i][j];
    board[i][j]='-';

    bool found = helper(board , n , m , i-1 , j , word , s+1)||
        helper(board , n , m , i+1 , j , word , s+1)||
        helper(board , n , m , i , j+1 , word , s+1)||
        helper(board , n , m , i , j-1 , word , s+1);

    board[i][j]= temp;
    return found;


}
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(board[i][j] == word[0]){
                if (helper(board, n, m, i, j, word, 0))
                    return true;
            }
        }
    }
    return false;
    }
};
