class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(),intervals.end());
        int prevEnd=intervals[0][1],cnt=0;
        for(int i=1;i<intervals.size();i++){
            if(prevEnd>intervals[i][0]){//previous ending interval is greater than the next's starting interval, then remove it so count++;
                prevEnd=min(prevEnd,intervals[i][1]);//comparing which one to remove
                cnt++;
            }
            else{
                prevEnd=intervals[i][1];//else update prevEnd value with current node ending value/interval
            }
        }
        return cnt; 
    }
};