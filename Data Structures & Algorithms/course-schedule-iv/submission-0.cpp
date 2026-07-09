class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> G(numCourses,vector<bool>(numCourses,false));
        for(auto &pr:prerequisites){
            G[pr[0]][pr[1]]=true;
        }
        for(int k=0;k<numCourses;k++){
            for(int i=0;i<numCourses;i++){
                for(int j=0;j<numCourses;j++){
                    if(G[i][k] && G[k][j]) G[i][j]=true;
                }
            }
        }
        vector<bool> ans;
        for(auto q:queries){
            ans.push_back(G[q[0]][q[1]]?true:false);
        }
        return ans;
    }
};