class Solution {
public:
    class edge{
        public:
        int v,wt;
        edge(int x,int y){
            v=x;
            wt=y;
        }
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<edge>> G(n);
        for(auto &el:flights){
            G[el[0]].push_back(edge(el[1],el[2]));
        }
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0]=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,0,src});
        while(!pq.empty()){
            auto [d,edges,u]=pq.top(); pq.pop();
            if(edges==k+1) continue;
            for(auto e:G[u]){
                if(dist[e.v][edges+1]>d+e.wt){
                    dist[e.v][edges+1]=d+e.wt;
                    pq.push({dist[e.v][edges+1],edges+1,e.v});
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<=k+1;i++){
            ans=min(ans,dist[dst][i]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
