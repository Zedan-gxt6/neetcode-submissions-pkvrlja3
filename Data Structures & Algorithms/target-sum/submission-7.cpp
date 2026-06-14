class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        if(target<0) target*=-1;
        for(auto num:nums) sum+=num;
        if(target>sum) return 0;
        if((sum+target)%2!=0) return 0;
        target=(sum+target)/2;
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(nums[i-1]<=j){
                    dp[i][j]+=dp[i-1][j-nums[i-1]];
                    dp[i][j]+=dp[i-1][j];
                }
                else dp[i][j]+=dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};
