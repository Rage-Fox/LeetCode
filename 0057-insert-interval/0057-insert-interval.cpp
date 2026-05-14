class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> v;
        int i=0;
        while(i<intervals.size() and newInterval[0]>intervals[i][1]){
            v.push_back(intervals[i]);
            i++;
        }
        while(i<intervals.size() and intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }
        v.push_back(newInterval);
        while(i<intervals.size()){
            v.push_back(intervals[i]);
            i++;
        }
        return v;
    }
};