class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int maxLeftScore=values[0];
        int res=0;
        for(int i=1;i<n;i++){
            int currentRightScore=values[i]-i;
            res=max(res,maxLeftScore+currentRightScore);
            int currentLeftScore=values[i]+i;
            maxLeftScore=max(maxLeftScore,currentLeftScore);
        }
        return res;
    }
};