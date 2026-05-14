class Solution {
public:
    int integerReplacement(int num) {
        int steps=0;
        long long n=num;
        while(n>1){
            if((n&1)==0){
                n>>=1;
            }
            else{
                /*
                    If n == 3 => do n--
                    Else if last two bits of n are 01 => n-- (because it reduces a 1-bit)
                    Else (last two bits are 11) => n++ (to create trailing zeros)
                    In Binary reasoning =>
                        (n & 3) == 1 means last two bits are 01
                        (n & 3) == 3 means last two bits are 11
                */
                if(n==3 || (n&3)==1){
                    n--;

                }
                else{
                    n++;
                }
            }
            steps++;
        }
        return steps;
    }
};