class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        if(n==3){
            return values[0]*values[1]*values[2];
        }
        // dp[i][j]=max weight for triangle values[i..j]
        vector<vector<int>> dp(n-1,vector<int>(n,0));
        for(int d=2;d<=n-1;d++){
            for(int i=0;i<n-d;i++){
                int j=i+d;
                int w=INT_MAX,e=values[i]*values[j];
                for(int k=i+1;k<j;k++){
                    w=min(w,e*values[k]+dp[i][k]+dp[k][j]);
                }
                dp[i][j]=w;
            } 
        }
        return dp[0][n-1];
    }
};