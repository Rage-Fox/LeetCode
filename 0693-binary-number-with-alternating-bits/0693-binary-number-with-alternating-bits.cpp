class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int x=n^(n>>1); // make all 1's
        return (x&(x+1))==0; // AND with it's next power of 2 makes the value 0 for alternate bits
    }
};