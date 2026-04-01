class Solution {
public:
    bool wordBreak(string s, vector<string>& d) {
        unordered_set<string> h;
        int n=s.size();
        for(string i:d) h.insert(i);
        vector<bool> dp(n,false);
        string str="";
        for(int i=0;i<n;i++){
            str+=s[i];
            if(h.find(str)!=h.end()) dp[i]=true;
            else{
                for(int j=1;j<=i;j++){
                    if(dp[j-1]){
                        if(h.find(str.substr(j)) != h.end()){
                            dp[i] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[n-1];
    }
};
