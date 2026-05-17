class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k==1){
            return r-l+1;
        }
        // max possible value of 'y' is kth root of 'r' because "kth-root(y)=x"
        int res=0,maxx=pow(r,1.0/k)+1;
        for(int x=0;x<=maxx;x++){
            long long y=pow(x,k);
            if(l<=y && y<=r){
                res++;
            }
        }
        return res;
    }
};