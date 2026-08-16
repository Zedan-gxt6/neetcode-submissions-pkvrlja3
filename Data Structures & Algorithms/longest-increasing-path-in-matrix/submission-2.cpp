class Solution {
    int maxLenght=1;
    vector<vector<int>> dp;
    vector<int> row = {0,0,-1,1};
    vector<int> col = {1,-1,0,0};
public:

    int DFS(vector<vector<int>> &matrix,int m,int n,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];

        for(int k=0;k<4;k++){
            int ni = i + row[k],nj = j + col[k];
            if(ni<m && ni>=0 && nj<n && nj>=0 && matrix[ni][nj]>matrix[i][j]){
                dp[i][j] = max(dp[i][j],DFS(matrix,m,n,ni,nj)+1);
            }
        }

        if(dp[i][j]==-1) dp[i][j]=1;

        maxLenght = max(maxLenght,dp[i][j]);
        
        return dp[i][j]; 
    }

    void initialiser(int m,int n){
        dp.resize(m,vector<int>(n,-1));
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        initialiser(m,n);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                DFS(matrix,m,n,i,j);
            }
        }
        
        return maxLenght;
    }
};