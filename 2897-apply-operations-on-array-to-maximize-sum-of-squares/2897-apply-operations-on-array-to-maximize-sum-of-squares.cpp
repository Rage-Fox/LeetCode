class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        // When a bit in 'a' is 1 and bit in 'b' is 0, OR swaps the values of
        // that bit Means 'a' becomes 0 bit and 'b' becomes 1 bit make large
        // numbers as large as possible and small numbers as small as possible
        const int MOD = 1e9 + 7;
        vector<int> bits(30, 0);
        for (int num : nums) {
            for (int i = 0; i < 30; i++) {
                if (num & (1 << i)) {
                    bits[i]++;
                }
            }
        }
        long long res = 0;
        for (int i = 0; i < k; i++) {
            long long cur = 0;
            for (int j = 29; j >= 0; j--) {
                if (bits[j] > 0) {
                    cur |= (1LL << j);
                    bits[j]--;
                }
            }
            res = (res + cur * cur) % MOD;
        }
        return (int)res;
    }
};