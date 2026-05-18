class Solution {
public:
    int isCycle(vector<vector<int>>& pq,int n,int i,vector<int> &vis){
        vis[i]=1;
        for(int j=0;j<pq.size();j++){
            int x=pq[j][0],y=pq[j][1];
            if(x==i){
                if(!vis[y]){ if(isCycle(pq,n,y,vis)) return 1;}
                else {return 1;}
            }
        }
        vis[i]=0;
        return 0;
    }
    bool canFinish(int n, vector<vector<int>>& pq) {
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(isCycle(pq,n,i,vis)) return false;
        }
        return true;
    }
};
