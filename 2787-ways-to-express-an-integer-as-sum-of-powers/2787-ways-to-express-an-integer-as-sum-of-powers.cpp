class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfWays(int n, int x) {
        // Step 1: Find the maximum number such that maxNum^x <= n
        int maxNum=1;
        while(pow(maxNum,x)<=n){
            maxNum++;
        }
        maxNum--;
        vector<vector<int>> dp(n+1,vector<int>(maxNum+1,0));
        // Base case: There is 1 way to form sum 0 (by choosing no numbers)
        for(int j=0;j<=maxNum;j++){
            dp[0][j]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=maxNum;j++){
                // Exclude the current number j
                dp[i][j]=dp[i][j-1];
                if(i>=pow(j,x)){
                    dp[i][j]=(dp[i][j]+dp[i-pow(j,x)][j-1])%MOD;
                }
            }
        }
        return dp[n][maxNum];
    }
};