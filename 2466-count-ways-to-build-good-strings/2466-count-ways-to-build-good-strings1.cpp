class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // https://leetcode.com/problems/count-ways-to-build-good-strings/solutions/3360551/count-ways-to-build-good-strings
        // Dynamic Programming
        int mod=1e9+7;
        vector<int> dp(high+1,0);
        dp[0]=1;
        for(int i=1;i<=high;i++){
            if(i>=zero){
                dp[i]+=dp[i-zero];
            }
            if(i>=one){
                dp[i]+=dp[i-one];
            }
            dp[i]%=mod;
        }
        int result=0;
        for(int i=low;i<=high;i++){
            result=(result+dp[i])%mod;
        }
        return result;
    }
};