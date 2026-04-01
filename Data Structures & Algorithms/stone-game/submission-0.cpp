class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        pair<int,int> dp[n][n];
        for(int i=0;i<n;i++){
            dp[i][i].first=piles[i];
            dp[i][i].second=0;
        }
        for(int len=2;len<n;len++){
            for(int i=0;i<n;i++){
                int j=i+len-1;
                if(j<n){
                    int turn1=piles[i]+dp[i+1][j].second;
                    int op1=dp[i+1][j].first;

                    int turn2=piles[j]+dp[i][j-1].second;
                    int op2=dp[i][j-1].first;

                    if(turn1>turn2){
                        dp[i][j].first=turn1;
                        dp[i][j].second=op1;
                    }
                    else{
                        dp[i][j].first=turn2;
                        dp[i][j].second=op2;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<"("<<dp[i][j].first<<","<<dp[i][j].second<<")"<<" ";
            }
            cout<<endl;
        }
        return dp[n-1][n-1].first>dp[n-1][n-1].second;
    }
};