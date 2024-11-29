class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        // Explanation-> https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/solutions/3230800/c-java-python-ping-pong-dijkstra/
        if(grid[0][1]>1 and grid[1][0]>1){
            return -1;
        }
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            int time=pq.top()[0],row=pq.top()[1],col=pq.top()[2];
            pq.pop();
            if(row==m-1 and col==n-1){
                return time;
            }
            if(visited[row][col]){
                continue;
            }
            visited[row][col]=true;
            for(auto dir:dirs){
                int r=row+dir[0],c=col+dir[1];
                if(r<0 or r>=m or c<0 or c>=n or visited[r][c]){
                    continue;
                }
                // If time for a neighbor (target) cell is > 1 + time for current cell. We can not directly move to target cell. We will have to "shift around" between previous cell and current cell. When shifting around between previous and current cell there can be two cases.
                // Even case: We reach in time+1
                // Odd case: We reach in time
                int wait=(grid[r][c]-time)%2==0;
                // Maximum because we have to have more time for visiting the next neighbouring cell
                pq.push({max(grid[r][c]+wait,time+1),r,c});
            }
        }
        return -1;
    }
};