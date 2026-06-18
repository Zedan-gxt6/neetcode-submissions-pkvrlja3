class Solution {
public:
    int helper(vector<int>& piles, int n, int turn, int idx, int M,
               vector<vector<vector<int>>>& dp) {

        if (idx >= n) return 0;

        if (dp[turn][idx][M] != -1)
            return dp[turn][idx][M];

        int opp = 1 - turn;

        if (turn == 0) { 

            int ans = 0;
            int taken = 0;

            for (int X = 1; X <= 2 * M && idx + X <= n; X++) {
                taken += piles[idx + X - 1];

                ans = max(
                    ans,
                    taken +
                    helper(piles, n, opp, idx + X, max(M, X), dp)
                );
            }

            return dp[turn][idx][M] = ans;
        }
        else { 

            int ans = INT_MAX;

            for (int X = 1; X <= 2 * M && idx + X <= n; X++) {

                ans = min(
                    ans,
                    helper(piles, n, opp, idx + X, max(M, X), dp)
                );
            }

            return dp[turn][idx][M] = ans;
        }
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        vector<vector<vector<int>>> dp(
            2,
            vector<vector<int>>(n + 1, vector<int>(n + 1, -1))
        );

        return helper(piles, n, 0, 0, 1, dp);
    }
};