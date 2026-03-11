class Solution {
public:
    int bitwiseComplement(int n) {
        // bit_width determines exact length of the binary representation (rather than giving 32)
        if(n==0){
            return 1;
        }
        return ~n&(1<<bit_width((unsigned)n))-1;
    }
};