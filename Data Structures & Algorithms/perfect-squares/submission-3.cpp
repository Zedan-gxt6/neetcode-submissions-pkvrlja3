class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,1); int mini;
        for(int i=2;i<=n;i++){
            mini=i;
            for(int j=1;j*j<=i;j++){
                if(j*j==i){
                    mini=1;
                    break;
                }
                mini=min(mini,dp[j*j]+dp[i-j*j]);
            }
            dp[i]=mini;
        }
        return dp[n];
    }
};