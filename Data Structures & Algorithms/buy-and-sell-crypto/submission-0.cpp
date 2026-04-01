class Solution {
public:
    int maxProfit(vector<int>& p) {
        int min=p[0],ans=0;
        for(int i=1;i<p.size();i++){
            if(p[i]<min) min=p[i];
            else if(ans<p[i]-min) ans=p[i]-min;
        }
        return ans;
    }
};
