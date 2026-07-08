class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;

        vector<int> dist(n, INF);
        vector<int> temp;
        dist[src] = 0;

        // k stops means at most k + 1 flights
        for (int i = 0; i <= k; i++) {
            temp = dist;
            for (auto &f : flights) {
                int u = f[0];
                int v = f[1];
                int wt = f[2];
                if (dist[u] != INF && dist[u] + wt < temp[v]) {
                    temp[v] = dist[u] + wt;
                }
            }
            dist = temp;
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};