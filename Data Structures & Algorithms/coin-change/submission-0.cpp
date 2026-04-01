class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0]=0; int mini,f=0;
        for(int i=1;i<=amount;i++){
            mini=INT_MAX; f=0;
            for(int j=0;j<coins.size();j++){
                if((i-coins[j])>=0 && dp[i-coins[j]]!=-1) {mini=min(mini,1+dp[i-coins[j]]); f=1;}
            }
            if(f) dp[i]=mini;
        }
        return dp[amount];
    }
};
