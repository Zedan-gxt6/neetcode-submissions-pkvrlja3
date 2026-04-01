class Solution {
public:
    void helper(const string &s, int a, int n,
                vector<string> &ans,
                vector<vector<string>> &final,
                vector<vector<bool>> &dp) {

        if (a == n) {
            final.push_back(ans);
            return;
        }

        for (int i = a; i < n; i++) {
            if (dp[a][i]) {
                ans.push_back(s.substr(a, i - a + 1));
                helper(s, i + 1, n, ans, final, dp);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i < n; i++) {
                int j = i + len - 1;
                if (j < n) {
                    if (s[i] == s[j]) {
                        if (len <= 2) dp[i][j] = true;
                        else dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
        }

        vector<vector<string>> final;
        vector<string> ans;

        helper(s, 0, n, ans, final, dp);

        return final;
    }
};