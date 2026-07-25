class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        return s + (long long)n / 2 * (m - 1) + (n > 1);
    }
};