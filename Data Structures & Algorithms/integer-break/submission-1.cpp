class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,1); int maxi;

        for(int i=2;i<=n;i++){
            maxi=0;
            for(int j=1;j<i;j++){
                maxi= max(maxi,j*max(i-j,dp[i-j]));
            }
            dp[i]=maxi;
        }
        return dp[n];
    }
};