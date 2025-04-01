typedef long long ll;
class Solution {
public:
    ll solve(ll idx,int n,vector<vector<int>> &questions,vector<ll> &dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        // Choice 1: Take the current question and unable to solve next questions
        ll take=solve(idx+questions[idx][1]+1,n,questions,dp)+questions[idx][0];
        // Choice 2: Skip the current question
        ll not_take=solve(idx+1,n,questions,dp);
        return dp[idx]=max(take,not_take);
    }
    ll mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<ll> dp(n+1,-1);
        return solve(0,n,questions,dp);
    }
};