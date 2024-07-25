class Solution {
public:
    int maxx=INT_MIN;
    void dfs(int node,vector<int> &edges,vector<int> &vis,vector<int> &pathvis,int score){
        // Already visited, simply return because if it is already visited, meaning that we have checked it in before cases already
        // Again traversing in the same path gives TLE as it may lead to end of the graph or else a Cycle which would've been detected earlier
        if(vis[node]==1){
            return;
        }
        // If no neighbouring edge from current node, just visit current node and simply return
        if(edges[node]==-1){
            vis[node]=1;
            return;
        }
        // If pathvis[node]!=0, means cycle is detected. Just subtract previous score from current score and find maximum one
        if(pathvis[node]!=0){
            maxx=max(maxx,score-pathvis[node]+1);
            return;
        }
        // Current pathvis value will be score+1
        pathvis[node]=score+1;
        // DFS call from current node to it's neighbouring node
        dfs(edges[node],edges,vis,pathvis,score+1);
        // After the DFS call, set pathvis[current node] to zero
        pathvis[node]=0;
        // Mark current node as visited
        vis[node]=1;
        return;
    }
    int longestCycle(vector<int> &edges){
        int v=edges.size();
        vector<int> vis(v,0),pathvis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,edges,vis,pathvis,0);
            }
        }
        return (maxx==INT_MIN)?-1:maxx;
    }
};