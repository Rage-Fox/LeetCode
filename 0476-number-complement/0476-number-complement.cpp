class Solution {
public:
    int findComplement(int num) {
        int nearest2Power=floor(log2(num))+1;
        return ((1LL<<nearest2Power)-1)^num;
    }
};