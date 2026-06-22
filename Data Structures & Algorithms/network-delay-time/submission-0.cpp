class Solution {
public:
    class edge {
    public:
        int v, wt;

        edge(int i, int j) {
            v = i;
            wt = j;
        }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<edge>> G(n + 1);

        for (auto &i : times) {
            G[i[0]].push_back(edge(i[1], i[2]));
        }

        struct Compare {
            bool operator()(edge a, edge b) {
                return a.wt > b.wt;
            }
        };

        priority_queue<edge, vector<edge>, Compare> pq;

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push(edge(k, 0));

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int u = top.v;
            int wt = top.wt;

            // if (wt > dist[u]) continue;

            for (auto ne : G[u]) {
                if (dist[ne.v] > wt + ne.wt) {
                    dist[ne.v] = wt + ne.wt;
                    pq.push(edge(ne.v, dist[ne.v]));
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};