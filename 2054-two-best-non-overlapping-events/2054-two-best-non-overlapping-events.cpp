class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<pair<int,int>> start,end;
        for(auto it:events){
            start.push_back({it[0],it[2]});
            end.push_back({it[1],it[2]});
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int si=0,ei=0,maxx=0,ans=0;
        while(si<start.size()){
            // Sum the value of current start events with the maximum value of end events which ended before it
            while(ei<end.size() and end[ei].first<start[si].first){
                maxx=max(maxx,end[ei].second);
                ei++;
            }
            ans=max(ans,start[si].second+maxx);
            si++;
        }
        return ans;
    }
};