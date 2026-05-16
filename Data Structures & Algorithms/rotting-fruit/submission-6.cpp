class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;
        int minutes = 0;

        queue<pair<int,int>> q;

        vector<int> r = {0,0,1,-1};
        vector<int> c = {1,-1,0,0};

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {

                if(grid[i][j] == 1)
                    fresh++;

                else if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }

        while(!q.empty() && fresh) {

            int sz = q.size();

            while(sz--) {

                auto front = q.front();
                q.pop();

                for(int i=0;i<4;i++) {

                    int x = front.first + r[i];
                    int y = front.second + c[i];

                    if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==1) {

                        grid[x][y] = 2;

                        fresh--;

                        q.push({x,y});
                    }
                }
            }

            minutes++;
        }

        if(fresh)
            return -1;

        return minutes;
    }
};