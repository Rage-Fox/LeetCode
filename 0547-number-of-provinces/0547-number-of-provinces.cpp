class Solution {
public:
    void dfs(int i,vector<int> &visited,vector<int> adj[]){
        visited[i]=1;
        for(auto it:adj[i]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j and isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                c++;
            }
        }
        return c;
    }
};