class Solution {
public:
    pair<int,int> findFarthestNode(int n,vector<vector<int>> &adj,int source){
        queue<int> q;
        vector<bool> visited(n,false);
        q.push(source);
        visited[source]=true;
        int maximumDistance=0,farthestNode=source;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int currentNode=q.front();
                q.pop();
                // The farthest node is the last one that was popped out of the queue.
                farthestNode=currentNode;
                for(int neighbor:adj[currentNode]){
                    if(!visited[neighbor]){
                        visited[neighbor]=true;
                        q.push(neighbor);
                    }
                }
            }
            if(!q.empty()){
                maximumDistance++;
            }
        }
        return {farthestNode,maximumDistance};
    }
    int findDiameter(int n,vector<vector<int>> &adj){
        auto [farthestNode,_]=findFarthestNode(n,adj,0);
        auto [_,diameter]=findFarthestNode(n,adj,farthestNode);
        return diameter;
    }
    vector<vector<int>> buildAdjList(int size,vector<vector<int>> &edges){
        vector<vector<int>> adj(size);
        for (auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // https://www.youtube.com/watch?v=tK1TLnhmXzw
        int n=edges1.size()+1,m=edges2.size()+1;
        vector<vector<int>> adjList1=buildAdjList(n,edges1);
        vector<vector<int>> adjList2=buildAdjList(m,edges2);
        int diameter1=findDiameter(n,adjList1);
        int diameter2=findDiameter(m,adjList2);
        int combinedDiameter=ceil(diameter1/2.0)+ceil(diameter2/2.0)+1;
        // Case-1: After merging, still the 1st tree has the minimum possible diameter
        // Case-2: After merging, still the 2nd tree has the minimum possible diameter
        // Case-3: As you're trying to form minimum, merging the middle of two longest diameters of both trees with a new edge may give minimum possible diameter
        return max({diameter1,diameter2,combinedDiameter});
    }
};