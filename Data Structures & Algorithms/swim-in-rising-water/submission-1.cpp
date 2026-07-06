class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        dist[0][0] = grid[0][0];

        vector<int> r = {0, 0, 1, -1};
        vector<int> c = {1, -1, 0, 0};

        pq.push({grid[0][0], 0, 0}); // {cost, row, col}

        while (!pq.empty()) {
            auto [cost, row, col] = pq.top();
            pq.pop();

            if (cost > dist[row][col]) continue;

            if (row == n - 1 && col == n - 1) {
                return cost;
            }

            for (int i = 0; i < 4; i++) {
                int x = row + r[i];
                int y = col + c[i];

                if (x >= 0 && y >= 0 && x < n && y < n) {
                    int newCost = max(cost, grid[x][y]);

                    if (newCost < dist[x][y]) {
                        dist[x][y] = newCost;
                        pq.push({newCost, x, y});
                    }
                }
            }
        }

        return dist[n - 1][n - 1];
    }
};