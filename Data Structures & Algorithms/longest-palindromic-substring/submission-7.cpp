class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=0;
        string ans=s.substr(0,1);
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int l=2;l<=n;l++){
            for(int start=0;start<=n-l;start++){
                    int i=start,j=start+l-1;
                    if((s[i]==s[j]) && (i+1>j-1 || dp[i+1][j-1])){
                        dp[i][j]=true;
                        if(l>maxi){
                            maxi=l;
                            ans=s.substr(i,l);
                        }
                    }
            }
        }
        return ans;
    }
};
