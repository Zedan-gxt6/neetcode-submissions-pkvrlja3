class Solution {
public:
     void dfs(vector<vector<int>>& grid,int n,int m,int i,int j,int* count){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==0) return;
        (*count)++;
        grid[i][j]=0;
        dfs(grid,n,m,i+1,j,count);
        dfs(grid,n,m,i-1,j,count);
        dfs(grid,n,m,i,j+1,count);
        dfs(grid,n,m,i,j-1,count);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int count=0;
                    dfs(grid,n,m,i,j,&count);
                    maxi=max(maxi,count);
                }
            }
        }
        return maxi;
    }
};

