class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        queue<tuple<int,int,int>> q;
        vector<int> r={0,0,1,-1};
        vector<int> c={1,-1,0,0};
        q.push({0,0,0});
        while(!q.empty()){
            auto [d,x,y]=q.front(); q.pop();
            for(int i=0;i<4;i++){
                int nx=x+r[i],ny=y+c[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int wt=abs(heights[nx][ny]-heights[x][y]);
                    if(dist[nx][ny]>max(wt,d)){
                        dist[nx][ny]=max(wt,d);
                        q.push({dist[nx][ny],nx,ny});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};