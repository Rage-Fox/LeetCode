class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        vector<int> dist1(n,1e9);
        vector<int> dist2(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int freq=1;
        while(!pq.empty()){
            int dist=pq.top().first,node=pq.top().second;
            pq.pop();
            // If red light, waiting period will be added
            // Red lights from 5-10, 15-20 which is odd multiple times (only the start state) of 5
            if((dist/change)%2==1){
                // Add the remaining waiting time
                dist+=(change-dist%change);
            }
            if(node==n-1){
                freq++;
            }
            // As two of the best shortest iterations are over, then break the traversing as we already found the answer
            if(freq>2 and node==n-1){
                break;
            }
            for(auto it:adj[node]){
                if(dist+time<dist1[it]){
                    // dist+time will be the shortest distance and dist1[it] will become second shortest distance
                    dist2[it]=dist1[it];
                    dist1[it]=dist+time;
                    pq.push({dist1[it],it});
                }
                // Greater than the shortest distance but smaller than the current second shortest distance stored, then only update dist2[it]
                else if(dist+time>dist1[it] and dist+time<dist2[it]){
                    dist2[it]=dist+time;
                    pq.push({dist2[it],it});
                }
            }
        }
        // Return the second shortest distance to reach the last node
        return dist2[n-1];
    }
};