class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));

        // base cases
        for(int j=1;j<=m;j++){
            bool isEvenLenghtRemaining = j%2==0;
            bool ans=true;
            if(isEvenLenghtRemaining){
                for(int k=0;k<j-1;k+=2){
                    bool firstValid = p[k]!='*';
                    bool secondValid = p[k+1]=='*';
                    if(!(firstValid && secondValid)){
                        ans=false;
                    } 
                }
            }
            else ans=false;
            dp[0][j]=ans;
        }
        dp[0][0]=true;

        //Tabulation
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    if(p[j-2]==s[i-1] || p[j-2]=='.') dp[i][j] = dp[i-1][j] || dp[i][j-2];
                    else dp[i][j] = dp[i][j-2];
                }
            }
        }
        return dp[n][m];
    }
};