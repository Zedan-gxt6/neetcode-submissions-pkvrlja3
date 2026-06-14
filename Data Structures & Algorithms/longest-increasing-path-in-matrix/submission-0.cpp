class Solution {
public:
    int dfs(vector<vector<int>>& mat,int m,int n,int i,int j,vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=0,nx,ny;
        vector<int> r={1,-1,0,0};
        vector<int> c={0,0,1,-1};
        for(int k=0;k<4;k++){
            nx=i+r[k]; ny=j+c[k];
            if(nx>=0 && ny>=0 && nx<m && ny<n && mat[nx][ny]>mat[i][j]){
                maxi=max(maxi,dfs(mat,m,n,nx,ny,dp));
            }
        }
        dp[i][j]=1+maxi;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=dfs(matrix,m,n,i,j,dp);
            }
        }
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi;
    }
};
