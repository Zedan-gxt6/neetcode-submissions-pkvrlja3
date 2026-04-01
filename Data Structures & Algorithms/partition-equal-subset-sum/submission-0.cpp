class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int w=0;
        for(int i:nums) w+=i;
        if(w%2==0) w=w/2;
        else return false;
        vector<vector<int>> dp(n+1,vector<int> (w+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                int wt=nums[i-1];
                if(wt<=j){
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt]+wt);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][w]==w;
    }
};
