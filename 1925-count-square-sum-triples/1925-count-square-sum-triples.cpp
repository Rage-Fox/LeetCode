class Solution {
public:
    int countTriples(int n) {
        int count=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                int k1=i*i;
                int k2=j*j;
                int ans1=sqrt(k1-k2);
                double ans2=sqrt(k1-k2);
                if(ans1==ans2){
                    count++;
                }
            }
        }
        return count;
    }
};