class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> curr(2,vector<int>(2));
        vector<vector<int>> next(2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            curr[0][0]=max(-prices[i]+next[1][1],next[0][0]);
            curr[0][1]=next[0][0];
            curr[1][0]=max(prices[i]+next[0][1],next[1][1]);
            curr[1][1]=max(prices[i]+next[0][1],next[1][1]);
            next=curr;
        }
        return curr[0][0];
    }
};
