class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        const int MOD = 1e9 + 7;
        long long pow10[100001];
        pow10[0] = 1;
        for (int i = 1; i < 100001; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        vector<int> sum(n + 1, 0);
        vector<long long> num_x(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            sum[i + 1] = sum[i] + d;
            num_x[i + 1] = (d > 0) ? (num_x[i] * 10 + d) % MOD : num_x[i];
            cnt[i + 1] = cnt[i] + (d > 0);
        }
        int m = queries.size();
        vector<int> res(m, 0);
        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1] + 1;
            int length = cnt[r] - cnt[l];
            long long val_x = (num_x[r] - (num_x[l] * pow10[length]) % MOD + MOD) % MOD;
            long long val_sum = sum[r] - sum[l];
            res[i] = (val_x * val_sum) % MOD;
        }
        return res;
    }
};