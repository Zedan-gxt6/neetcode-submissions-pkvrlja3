class Solution {
public:
    void dfs(vector<vector<char>>& board,int m,int n,int i,int j){
        board[i][j]='V';
        vector<int> r={0,0,1,-1};
        vector<int> c={1,-1,0,0};
        for(int k=0;k<4;k++){
            int x=i+r[k],y=j+c[k];
            if(x<m && y<n && x>=0 && y>=0 && board[x][y]=='O'){
                dfs(board,m,n,x,y);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && board[i][j]=='O'){
                    dfs(board,m,n,i,j);
                }
            }
        }

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(board[i][j]=='O') board[i][j]='X';
               else if(board[i][j]=='V') board[i][j]='O';
            }
        }
    }
};
