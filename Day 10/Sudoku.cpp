class Solution {
public:
    bool issafe(vector<vector<char>>& board,int i,int j,char value){
        for(int m=0;m<9;m++){
            if(board[m][j]==value) return false;
            if(board[i][m]==value) return false;
            if(board[i-i%3+(m/3)][j-j%3+(m%3)]==value) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int i,int j){
        if(i==board.size() ) return true;
        else if(j==board.size()) return solve(board,i+1,0);
        else if(board[i][j]!='.') return solve(board,i,j+1);
        else{
            for(char a='1';a<='9';a++){
                if(issafe(board,i,j,a)){
                    board[i][j]=a;
                    if(solve(board,i,j+1)){
                        return true;
                    }
                    board[i][j]='.';
                }
            }
            return false;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};