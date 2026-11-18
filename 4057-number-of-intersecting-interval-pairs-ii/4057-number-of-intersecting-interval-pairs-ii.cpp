class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end());
        pq.push(intervals[0][1]);
        long long int sol = 0;
        for (int i = 1; i < intervals.size(); i++) {
            while (!pq.empty() && pq.top() < intervals[i][0]) {
                pq.pop();
            }
            // Pairs will be formed with all it's previous intervals
            sol += pq.size();
            pq.push(intervals[i][1]);
        }
        return sol;
    }
};