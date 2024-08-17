class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size(),n=points[0].size();
        vector<long long> dp(n,0);
        long long ans=0;
        for(int i=0;i<m;i++){
            // Summing up all the points in columns and placing them in column wise sum
            for(int j=0;j<n;j++){
                dp[j]+=points[i][j];
            }
            // What if you pick the number from previous column?
            for(int j=1;j<n;j++){
                dp[j]=max(dp[j],dp[j-1]-1);
            }
            // What if you pick the number from next column?
            for(int j=n-2;j>=0;j--){
                dp[j]=max(dp[j],dp[j+1]-1);
            }
        }
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};