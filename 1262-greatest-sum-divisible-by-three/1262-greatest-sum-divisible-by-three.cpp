class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp={0,INT_MIN,INT_MIN};
        for(int x:nums){
            vector<int> newdp=dp;
            for(int r=0;r<3;r++){
                int nr=(r+x)%3;
                newdp[nr]=max(newdp[nr],dp[r]+x);
            }
            dp=newdp;
        }
        return dp[0];
    }
};