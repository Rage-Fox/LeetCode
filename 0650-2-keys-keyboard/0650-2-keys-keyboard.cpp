class Solution {
public:
    int minSteps(int n) {
        vector<int>dp(n+1,0);
        for(int i=2;i<=n;i++){
            int minn=INT_MAX;
            for(int j=2;j<=i;j++){
                if(i%j==0){
                    // 1 copy + (j-1) paste = j operations
                    minn=min(minn,j+dp[i/j]);
                }
            }
            dp[i]=minn;
        }
        return dp[n];
    }
};