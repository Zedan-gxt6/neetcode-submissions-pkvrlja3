class Solution {
public:
    bool isSafe(vector<string> &board,int row,int col){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j>=0;i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void NQueens(vector<string> &board,int n,int row,vector<vector<string>> &final){
        if(row==n){
            final.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
           if(isSafe(board,row,i)){
                board[row][i]='Q';
                NQueens(board,n,row+1,final);
                board[row][i]='.';
           } 
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> final;
        vector<string> ans;
        string temp="";
        for(int i=0;i<n;i++) temp+=".";
        for(int i=0;i<n;i++) ans.push_back(temp);
        NQueens(ans,n,0,final);
        return final;
    }
};
