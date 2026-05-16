class Solution {
public:
    class node {
        public:
        int x;
        int y;
        int d;
    };
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<node> q;
        int m=grid.size(),n=grid[0].size();
        vector<int> r={0,0,1,-1};
        vector<int> c={1,-1,0,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty()){
            node temp=q.front(); q.pop();
            for(int i=0;i<4;i++){
                int a=temp.x+r[i],b=temp.y+c[i];
                if(a<m && b<n && a>=0 && b>=0){
                    if(grid[a][b]>temp.d+1){
                        grid[a][b]=temp.d+1;
                        q.push({a,b,temp.d+1});
                    }
                }
            }
        }
    }
};
