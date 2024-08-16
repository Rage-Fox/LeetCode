class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res=0,currmin=10000,currmax=-10000;
        for(auto a:arrays){
            // Max of currentMax-prevMin and prevMax-currentMin
            res=max(res,max(a.back()-currmin,currmax-a.front()));
            currmin=min(currmin,a.front());
            currmax=max(currmax,a.back());
        }
        return res;
    }
};