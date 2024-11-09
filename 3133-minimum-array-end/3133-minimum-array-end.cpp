class Solution {
public:
    long long minEnd(int n, int x) {
        bitset<64> X(x),N(n-1),ans=0;
        // When x has ith bit set, the answer has ith bit set
        // Otherwise set ith bit of answer to be jth bit of n-1 and move j
        for(int i=0,j=0;i<56;i++){
            ans[i]=(X[i])?1:N[j++];
        }
        return ans.to_ullong();
    }
};