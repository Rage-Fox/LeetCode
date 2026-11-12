class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        // Backwards
        int n = monsters.size();
        vector<long long> diff(n, 0);
        for (const auto& boost : boosts) {
            int l = boost[0], r = boost[1], v = boost[2];
            diff[r] += v;
            if (l > 0) {
                diff[l - 1] -= v;
            }
        }
        long long res = 0, bonus = 0;
        for (int i = n - 1; i >= 0; i--) {
            bonus += diff[i];
            if (res > 0) {
                res += monsters[i];
            } else {
                res = max(0LL, (long long)monsters[i] - bonus);
            }
        }
        return res;
    }
};