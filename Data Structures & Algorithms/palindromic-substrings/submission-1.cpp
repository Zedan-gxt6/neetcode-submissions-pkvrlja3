class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int l=2;l<=n;l++){
            for(int start=0;start<=n-l;start++){
                int i=start,j=start+l-1;
                if((s[i]==s[j]) && (l==2 || dp[i+1][j-1])) dp[i][j]=true;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]) count++;
            }
        }
        return count;
    }
};
