class Solution {
public:
    bool validDigit(int n, int x) {
        int c=0,f=0;
        while(n){
            if(n<10 and n!=x){
                f=1;
            }
            if(n%10==x){
                c++;
            }
            n/=10;
        }
        return c and f;
    }
};