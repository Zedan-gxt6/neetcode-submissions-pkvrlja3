class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prs) {
        vector<vector<int>> G(n);
        vector<int> indegree(n,0);
        for(auto &pr:prs){
            G[pr[1]].push_back(pr[0]);
            indegree[pr[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(auto v:G[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        vector<int> empty;
        return ans.size()==n ? ans:empty;
    }
};
