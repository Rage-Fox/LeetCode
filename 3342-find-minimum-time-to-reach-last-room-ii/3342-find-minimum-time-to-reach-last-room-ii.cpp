class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m=moveTime.size(),n=moveTime[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        pq.push({0,0,0,1}); // currentTime, x, y, move
        dist[0][0]=0;
        // Dijkstra's
        while(!pq.empty()){
            vector<int> curr=pq.top();
            pq.pop();
            int weight=curr[0];
            int x=curr[1];
            int y=curr[2];
            int move=curr[3];
            if(weight>dist[x][y]){
                continue;
            }
            for(vector<int> &dir:directions){
                int row=x+dir[0];
                int col=y+dir[1];
                if(row>=0 && row<m && col>=0 && col<n){
                    int time=max(weight,moveTime[row][col])+move;
                    if(dist[row][col]>time){
                        dist[row][col]=time;
                        int nextMove=move%2?2:1; // If move is 2, nextMove will be 1 and vice-versa
                        pq.push({time,row,col,nextMove});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};