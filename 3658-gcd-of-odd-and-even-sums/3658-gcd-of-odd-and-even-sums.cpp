class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // gcd(n^2,n*(n+1))=n*gcd(n,n+1)
        // two consecutive integers are always coprime, gcd(n,n+1)=1
        return n;
    }
};