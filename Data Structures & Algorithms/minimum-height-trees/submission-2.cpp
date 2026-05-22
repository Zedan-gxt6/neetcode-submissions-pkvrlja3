class Solution {
public:

    void dfs(vector<vector<int>> &A,
             int node,
             int parent,
             vector<int> &path,
             int depth,
             int &maxi,
             vector<int> &finalPath){

        path.push_back(node);

        if(depth > maxi){
            maxi = depth;
            finalPath = path;
        }

        for(auto ne : A[node]){

            if(ne == parent) continue;

            dfs(A, ne, node,
                path, depth + 1,
                maxi, finalPath);
        }

        path.pop_back();
    }

    vector<int> findMinHeightTrees(int n,vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> A(n);
        for(auto &e : edges){
            A[e[0]].push_back(e[1]);
            A[e[1]].push_back(e[0]);
        }

        int maxi = -1;
        vector<int> temp;
        vector<int> path;

        // first DFS
        dfs(A,0,-1,temp,0,maxi,path);

        int start = path.back();

        // second DFS
        maxi = -1;
        temp.clear();
        path.clear();

        dfs(A,start,-1,temp,0,maxi,path);

        int m = path.size();

        if(m % 2 == 1){

            return {path[m/2]};
        }

        return {path[m/2 - 1], path[m/2]};
    }
};