class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct Compare{
            bool operator()(vector<int> a,vector<int> b){
                return (a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
            }
        };
        priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
        for(auto &point:points) pq.push(point);
        while(pq.size()>k) pq.pop();
        vector<vector<int>> ans;
        while(pq.size()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
