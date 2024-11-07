class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // Maximum bit of 1's at a position is an answer
        int ans=0;
        for(int i=0;i<32;i++){
            int t=0;
            for(auto j:candidates){
                if(j&(1<<i)){
                    t++;
                }
            }
            ans=max(ans,t);
        }
        return ans;
    }
};