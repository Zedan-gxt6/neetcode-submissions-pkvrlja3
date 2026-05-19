class Solution {
public:
    bool isCycle(vector<vector<int>> &A,int n,int i,vector<int> &vis){
        if(vis[i]==1) return true;
        if(vis[i]==2) return false;

        vis[i]=1;
        for(auto ni:A[i]) if(isCycle(A,n,ni,vis)) return true;

        vis[i]=2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto &e:prerequisites) adj[e[1]].push_back(e[0]);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(isCycle(adj,n,i,vis)) return false;
        }
        return true;
    }
};
