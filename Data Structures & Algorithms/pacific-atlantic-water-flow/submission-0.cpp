class Solution {
public:
    void dfs(vector<vector<int>>& h,int m,int n,int i,int j,vector<vector<bool>> &V){
        V[i][j]=true;
        vector<int> r={0,0,1,-1};
        vector<int> c={1,-1,0,0};
        for(int k=0;k<4;k++){
            int x=i+r[k],y=j+c[k];
            if(x<m && y<n && x>=0 && y>=0 && !V[x][y] && h[x][y]>=h[i][j]){
                dfs(h,m,n,x,y,V);
            } 
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m=h.size(),n=h[0].size();

        vector<vector<bool>> P(m,vector<bool>(n,false)); //pacific visited
        vector<vector<bool>> A(m,vector<bool>(n,false)); //atlantic visited

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0) dfs(h,m,n,i,j,P);
                if(i==m-1 || j==n-1) dfs(h,m,n,i,j,A);
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j] && P[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
