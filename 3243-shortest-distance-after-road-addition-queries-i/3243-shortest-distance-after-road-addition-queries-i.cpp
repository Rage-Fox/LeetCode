class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dis(n,0);
        vector<int> adj[505];
        vector<int> ans;
        for(int i=0;i<n;i++){
            dis[i]=i;
            if(i!=0){
                adj[i].push_back(i-1);
            }
        }
        for(auto q:queries){
            adj[q[1]].push_back(q[0]);
            for(int i=0;i<n;i++){
                for(auto u:adj[i]){
                    if(dis[i]>dis[u]+1){
                        dis[i]=dis[u]+1;
                    }
                }
            }
            ans.push_back(dis[n-1]);
        }
        return ans;
    }
};