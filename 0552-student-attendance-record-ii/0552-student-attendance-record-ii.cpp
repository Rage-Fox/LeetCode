class Solution {
public:
    int mod=1e9+7;
    int solve(int n,int a,int b,vector<vector<vector<int>>> &dp){
        if(a<=0)
            return 0;
        if(b<=0)
            return 0;
        if(n<=0)
            return 1;
        if(dp[n][a][b]!=-1)
            return dp[n][a][b];
        // present+absent+latecounts
        return dp[n][a][b]=((solve(n-1,a,3,dp)+solve(n-1,a-1,3,dp))%mod+solve(n-1,a,b-1,dp))%mod;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(4,-1)));
        return solve(n,2,3,dp);
    }
};