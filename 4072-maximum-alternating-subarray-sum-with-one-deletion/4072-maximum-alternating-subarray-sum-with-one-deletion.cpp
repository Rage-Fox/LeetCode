class Solution {
public:
    int n;
    vector<vector<vector<long long>>> dp;
    long long f(int i, int parity, int deleted, vector<int>& nums) {
        if (i == n)
            return -1e9;
        if (dp[i][parity][deleted] != -1e9)
            return dp[i][parity][deleted];
        long long take = (parity == 0 ? nums[i] : -nums[i]);
        long long next = f(i + 1, 1 - parity, deleted, nums);
        long long ans = max(take, take + next);
        if (!deleted) {
            // parity stays the same if it's not deleted
            long long del = f(i + 1, parity, 1, nums);
            ans = max(ans, del);
        }
        return dp[i][parity][deleted] = ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        this->n = nums.size();
        long long ans = -1e9;
        dp.assign(n, vector<vector<long long>>(2, vector<long long>(2, -1e9)));
        for (int i = 0; i < n; i++) {
            ans = max(ans, f(i, 0, 0, nums));
        }
        return ans;
    }
};