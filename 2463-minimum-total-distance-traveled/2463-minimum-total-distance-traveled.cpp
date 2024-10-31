typedef long long ll;
class Solution {
public:
    ll minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        vector<ll> facts;
        for(auto fact:factory){
            int pos=fact[0],limit=fact[1];
            while(limit--){
                facts.push_back(pos);
            }
        }
        sort(facts.begin(),facts.end());
        int n=facts.size(),m=robot.size();
        vector<vector<ll>> dp(n,vector<ll>(m,1e18));
        dp[0][0]=abs(facts[0]-robot[0]);
        for(int i=1;i<n;i++){
            dp[i][0]=min(dp[i-1][0],abs(facts[i]-robot[0]));
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+abs(facts[i]-robot[j]));
            }
        }
        return dp[n-1][m-1];
    }
};