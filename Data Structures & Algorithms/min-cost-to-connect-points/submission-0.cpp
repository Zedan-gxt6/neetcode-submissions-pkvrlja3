class Solution {
public:
    class edge{
        public:
        int x,y,wt;
        edge(int x,int y,int wt){
            this->x=x;
            this->y=y;
            this->wt=wt;
        }
    };
    int manh(int x1,int y1,int x2,int y2){
        return abs(x1-x2)+abs(y1-y2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        struct compare{
            bool operator()(edge a,edge b){
                return a.wt>b.wt;
            }
        };
        priority_queue<edge,vector<edge>,compare> pq;
        set<pair<int,int>> mst;
        int sum=0;
        pq.push(edge(points[0][0],points[0][1],0));
        while(!pq.empty()){
            auto top=pq.top(); pq.pop();
            if(mst.find({top.x,top.y})==mst.end()){
                sum+=top.wt;
                mst.insert({top.x,top.y});
                for(auto &point:points){
                    if(mst.find({point[0],point[1]})==mst.end()){
                        pq.push(edge(point[0],point[1],manh(top.x,top.y,point[0],point[1])));
                    }
                }
            }
        }
        return sum;
    }
};
