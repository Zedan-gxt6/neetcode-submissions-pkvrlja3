class Solution {
public:
    void helper(int i,int n,int at,int al,vector<int> &ans,vector<vector<int>> &final){
        if(al==0){
            for(int k=i;k<=n;k++) ans.push_back(k);
            final.push_back(ans);
            for(int k=i;k<=n;k++) ans.pop_back();
            return;
        }
        if(at==0){
            final.push_back(ans);
            return;
        }
        helper(i+1,n,at,al-1,ans,final);
        ans.push_back(i);
        helper(i+1,n,at-1,al,ans,final);
        ans.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> final;
        vector<int> ans;
        helper(1,n,k,n-k,ans,final);
        // al=AllowedLeaves , at=AllowedTakes
        return final;
    }
};