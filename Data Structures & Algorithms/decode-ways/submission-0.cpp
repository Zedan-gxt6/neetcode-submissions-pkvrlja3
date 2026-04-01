class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
         dp[0]=1;
         dp[1]=s[0]!='0'?1:0;
        for(int i=2;i<=n;i++){
            if(s[i-1]!='0') dp[i]+=dp[i-1];
            if((10*(s[i-2]-'0')+s[i-1]-'0')<=26 && s[i-2]!='0') dp[i]+=dp[i-2];
           
        }
        return dp[n];
    }
};
