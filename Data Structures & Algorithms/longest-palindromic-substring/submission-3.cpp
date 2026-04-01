class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return "";
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int maxl = 1;
        int maxi = 1;
        for(int j = 1; j <= n; j++) {
            dp[1][j] = 1;
        }
        for(int len = 2; len <= n; len++) {
            for(int j = 1; j + len - 1 <= n; j++) {
                if(s[j-1] == s[j+len-2]) {
                    if(len == 2 || dp[len-2][j+1]) {
                        dp[len][j] = 1;
                        if(len > maxl) {
                            maxl = len;
                            maxi = j;
                        }
                    }
                }
            }
        }

        return s.substr(maxi-1, maxl);
    }
};
