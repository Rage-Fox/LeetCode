class Solution {
public:
    int climbStairs(int n) {
        // Binet's Formula - Calculating Fib(n+1) without it's previous values
        double sqrt5=sqrt(5);
        double phi=(1+sqrt5)/2;
        double psi=(1-sqrt5)/2;
        n++;
        return round((pow(phi,n)-pow(psi,n))/sqrt5);
    }
};