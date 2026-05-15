class Solution {
public:
    void dfs(vector<vector<char>>& grid,int n,int m,int i,int j){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]=='0') return;
        grid[i][j]='0';
        dfs(grid,n,m,i+1,j);
        dfs(grid,n,m,i-1,j);
        dfs(grid,n,m,i,j+1);
        dfs(grid,n,m,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,n,m,i,j);
                    count++;
                }
            }
        }
        return count;

    }
};
