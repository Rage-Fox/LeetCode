class Solution {
public:
    long long coloredCells(int n) {
        // 1+(4×1)+(4×2)+...+(4×(n−1))
        // 1+4×[((n−1)×n)/2]
        // 1+2×(n−1)×n
        return 1+(long long)n*(n-1)*2;
    }
};