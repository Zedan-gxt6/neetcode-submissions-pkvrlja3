class Solution {
public:
    bool isPalindrome(string s,int i,int j){
        if(i>=j) return true;
        if(s[i]==s[j]) return isPalindrome(s,i+1,j-1);
        return false;
    }
    void helper(string s,int a,int n,vector<string> &ans,vector<vector<string>> &final){
        if(a==n){
            final.push_back(ans);
            return;
        }
        for(int i=a;i<n;i++){
            if(isPalindrome(s,a,i)){
                ans.push_back(s.substr(a,i-a+1));
                helper(s,i+1,n,ans,final);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
         vector<vector<string>> final;
          vector<string> ans;
          helper(s,0,n,ans,final);
          return final;
    }
};
