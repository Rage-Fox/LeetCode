class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int last=0,maxx=INT_MIN;
        for(int i=0;i<gain.size();i++){
            maxx=max(last,maxx);
            last=last+gain[i];
        }
        return max(maxx,last);
    }
};