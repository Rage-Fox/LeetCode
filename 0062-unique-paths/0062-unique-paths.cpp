class Solution {
public:
    bool issafe(int i,int j,int m,int n){
        if(i>=0 && j>=0 && i<m && j<n)
            return true;
        return false;
    }
    int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
        // base case 
        if(i==m-1 && j==n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = 0;
        // right check 
        if(issafe(i,j+1,m,n))
            ans+=solve(i,j+1,m,n,dp);
        // down check
        if(issafe(i+1,j,m,n))
            ans+=solve(i+1,j,m,n,dp);
        return dp[i][j] = ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};