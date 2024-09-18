class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int currmax=-1,resans=0;
        for(int i=0;i<arr.size();i++){
            currmax=max(currmax,arr[i]);
            resans+=(currmax==i);
        }
        return resans;
    }
};