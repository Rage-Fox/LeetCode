class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int score = 1; score <= n; score++) {
            for (int len = 1;; len++) {
                int streakScore = len * (len + 1) / 2;
                if (streakScore > score) {
                    break;
                }
                int remaining = score - streakScore;
                if (dp[remaining] == INT_MAX) {
                    continue;
                }
                int skip = (remaining == 0) ? 0 : 1;
                dp[score] = min(dp[score], dp[remaining] + len + skip);
            }
        }
        return dp[n];
    }
};