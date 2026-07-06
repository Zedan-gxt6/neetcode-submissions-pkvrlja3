class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        dist[0][0]=grid[0][0];
        vector<int> r={0,0,1,-1};
        vector<int> c={1,-1,0,0};
        q.push({0,0});
        while(!q.empty()){
            auto top=q.front(); q.pop();
            for(int i=0;i<4;i++){
                int x=top.first+r[i],y=top.second+c[i];
                if(x>=0 && y>=0 && x<n && y<n){
                    if(max(dist[top.first][top.second],grid[x][y])<dist[x][y]){
                        dist[x][y]=max(dist[top.first][top.second],grid[x][y]);
                        q.push({x,y});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};
