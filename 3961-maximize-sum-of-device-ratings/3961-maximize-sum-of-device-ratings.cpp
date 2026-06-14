class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        // Each device's rating is its weakest unit
        // So let every device toss its smallest unit into one "sink" device
        // Which makes everyone else keeps their second-smallest as the new rating
        // The sink soaks up all the junk (ending up at the global minimum)
        int m = units.size();
        int n = units[0].size();
        if(n == 1){
            int ans = 0;
            for(auto& r : units){
                ans += r[0];
            }
            return ans;
        }
        long long ans = 0;
        int gMin = INT_MAX;
        int mnSec = INT_MAX;
        for(auto& it : units){
            sort(it.begin(), it.end());
            gMin = min(gMin, it[0]);
            mnSec = min(mnSec, it[1]);
            ans += it[1];
        }
        return (ans - mnSec + gMin);
    }
};