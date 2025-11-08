class Solution {
public:
    int minimumOneBitOperations(int n) {
        int last=0,ans=0;
        for(int i=31;i>=0;i--){
            if(n&(1<<i)){
                if(last==1) last=0;
                else{
                    ans+=(1<<i);
                    last=1;
                }
            }
            else if(last==1){
                ans+=(1<<i);
            }
        }
        return ans;
    }
};