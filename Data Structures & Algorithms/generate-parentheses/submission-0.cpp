class Solution {
public:
    void helper(int l,int r,int n,string &curr,vector<string> &ans){

        if(l==r && l==n){
            ans.push_back(curr);
            return;
        }

        if(l<n){
            curr.push_back('(');
            helper(l+1,r,n,curr,ans);
            curr.pop_back();
        }
        
        if(r<l){
            curr.push_back(')');
            helper(l,r+1,n,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        helper(0,0,n,curr,ans);
        return ans;
    }
};
