class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int wt=0,total=0;
        for(auto val:stones) total+=val;
        if(total%2==0) wt=total/2;
        else wt=(total/2)+1;
        vector<vector<int>> dp(n+1,vector<int>(wt+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=wt;j++){
                if(stones[i-1]<=j){
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-stones[i-1]]+stones[i-1]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        int s1=dp[n][wt],s2=total-dp[n][wt];
        return s1>s2?s1-s2:s2-s1;
    }
};