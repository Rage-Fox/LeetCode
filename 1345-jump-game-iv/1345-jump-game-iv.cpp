class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mpp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<int> vis(n,-1);
        vis[0]=1;
        int minn=1e9+7;
        while(!q.empty()){
            int node=q.front().first,score=q.front().second;
            q.pop();
            if(node==n-1){
                return score;
            }
            if(node+1<n and vis[node+1]==-1){
                vis[node+1]=1;
                q.push({node+1,score+1});
            }
            if(node-1>=0 and vis[node-1]==-1){
                vis[node-1]=1;
                q.push({node-1,score+1});
            }
            for(auto it:mpp[arr[node]]){
                if(vis[it]==-1){
                    vis[it]=1;
                    q.push({it,score+1});
                }
            }
            // Removing this leads to TLE as we pushed all possible arr[i]=arr[j] to the queue and we don't need to check again!
            mpp[arr[node]].clear();
        }
        return minn;
    }
};