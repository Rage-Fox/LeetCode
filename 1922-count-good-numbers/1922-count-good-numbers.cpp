class Solution {
public:
    const int MOD=1e9+7;
    long long power(long long base,long long exp){
        long long result=1;
        while(exp>0){
            if(exp%2==1){
                result=(result*base)%MOD;
            }
            base=(base*base)%MOD;
            exp/=2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        /*
        A string is good if:
            All even indices (0-based) can have digits: {0, 2, 4, 6, 8} → 5 choices
            All odd indices can have digits: {2, 3, 5, 7} → 4 choices
        So, total good numbers = (5 ^ number of even positions) * (4 ^ number of odd positions)
        If n is the total length:
            Even positions = (n + 1) / 2
            Odd positions = n / 2
        Since the values can be large, we compute the powers using modular exponentiation with mod = 1e9 + 7.
        */
        long long even=(n+1)/2;
        long long odd=n/2;
        long long ans=(power(5,even)*power(4,odd))%MOD;
        return ans;
    }
};