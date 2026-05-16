class Solution {
public:
    int numTrees(int n) {
        // ((2n)!)/(((n+1)!)*(n!))
        // =>((2n*2n-1*.....*n+1*(n!))/(((n+1)*n!)*n!))
        // =>((2n*2n-1*.....*n+1)/((n+1)*n!))
        long long res=1;
        for(int i=1;i<=n;i++){
            res*=(n+i);
            res/=i;
        }
        return res/(n+1);
    }
};