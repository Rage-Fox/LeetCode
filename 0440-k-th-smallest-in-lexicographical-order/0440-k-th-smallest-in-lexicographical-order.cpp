class Solution {
public:
    int currentnode(long n,long cur){
        int total=0;
        long next=cur+1;
        while(cur<=n){
            total+=min(n-cur+1,next-cur);
            cur*=10;
            next*=10;
        }
        return total;
    }
    int findKthNumber(int n, int k) {
        long cur=1;
        k--;
        while(k>0){
            int nodes=currentnode(n,cur);
            if(k>=nodes){
                cur+=1;
                k-=nodes;
            }
            else {
                cur*=10;
                k--;
            }
        }
        return (int)cur;
    }
};