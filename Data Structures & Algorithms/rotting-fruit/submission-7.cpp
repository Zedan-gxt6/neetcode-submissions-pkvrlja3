class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        int qsize=q.size(),tempn,minutes=0;
        vector<int> r={0,0,1,-1};
        vector<int> c={1,-1,0,0};
        while(!q.empty()){
            tempn=qsize;
            if(!fresh) return minutes;
            while(tempn){
                auto top=q.front();
                for(int i=0;i<4;i++){
                    int x=top.first+r[i],y=top.second+c[i];
                    if(x<m && y<n && x>=0 && y>=0 && grid[x][y]==1){
                        fresh--;
                        grid[x][y]=2;
                        q.push({x,y});
                        qsize++;
                    }
                }
                q.pop();
                qsize--;
                tempn--;
            }
            minutes++;
        }
        if(fresh) return -1;
        return minutes;
    }
};
