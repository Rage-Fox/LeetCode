class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int ans=INT_MAX;
                for(int k=0;k<m;k++){
                    if(j!=k)
                        ans=min(ans,matrix[i][j]+dp[i-1][k]);
                }
                dp[i][j]=ans;
            }
        }
        int mini=dp[n-1][0];
        for(int j=1;j<m;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }
};