class Solution {
public:
    int dp[2][101][1001];
    int solve(const int& k, const vector<int>& prices, int idx,
              int noOfTransaction, bool hasPurchased) {
        if (noOfTransaction == k && !hasPurchased)
            return 0;
        if (idx >= prices.size())
            return 0;
        if (dp[hasPurchased][noOfTransaction][idx] != -1)
            return dp[hasPurchased][noOfTransaction][idx];
        int ans = 0;
        if (!hasPurchased) {
            int buyCurrStock =
                solve(k, prices, idx + 1, noOfTransaction + 1, true) -
                prices[idx];
            ans = max(ans, buyCurrStock);
        } else {
            int sellCurrStock =
                solve(k, prices, idx + 1, noOfTransaction, false) + prices[idx];
            ans = max(ans, sellCurrStock);
        }
        int skipCurrStock =
            solve(k, prices, idx + 1, noOfTransaction, hasPurchased);
        ans = max(ans, skipCurrStock);
        return dp[hasPurchased][noOfTransaction][idx] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(k, prices, 0, 0, false);
    }
};