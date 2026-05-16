class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int minutes=0,fresh=0;
        queue<pair<int,int>> q;
        vector<int> r={0,0,1,-1};
        vector<int> c={1,-1,0,0};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }

        while(!q.empty()){
            int tempn=q.size();
            if(fresh){
            while(tempn--){
                    pair<int,int> front=q.front(); q.pop();
                    for(int i=0;i<4;i++){
                        int x=front.first+r[i],y=front.second+c[i];
                        if(x<m && y<n && x>=0 && y>=0 && grid[x][y]==1){
                            grid[x][y]=2;
                            fresh--;
                            q.push({x,y});
                        }
                    }
                }
            }
            else  return minutes;
            minutes++;
        }
        if(fresh) return -1;
        return minutes;
    }
};
