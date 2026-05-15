class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),per=0;
        vector<int> r={0,0,1,-1};
        vector<int> c={1,-1,0,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    for(int k=0;k<4;k++){
                        int x=i+r[k],y=j+c[k];
                        if(x<n && y<m && x>=0 && y>=0){
                            if(grid[x][y]==0) per++;
                        }
                        else per++;
                    }
                }
            }
        }
        return per;
    }
};