class Solution {
public:
    bool isCycle(vector<vector<int>> &A,int n,int i,int par,vector<int> &vis){
        vis[i]=1;
        for(auto ni:A[i]){
            if(!vis[ni]) {if(isCycle(A,n,ni,i,vis)) return true;} //This braces are very important else the below else if attaches to this if even if intended with parent if.
            else if(ni!=par) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> A(n);
        for(auto &e:edges){
            A[e[0]].push_back(e[1]);
            A[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycle(A,n,i,-1,vis)) return false;
                count++;
            } 
        }
        if(count>1) return false;
        return true;
    }
};
