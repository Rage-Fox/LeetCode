class Solution {
public:
    vector<vector<int>> getAncestors(int n,vector<vector<int>> &edg){
        // Using Topological Sort/Kahn's BFS Algorithm
        vector<vector<int>> edges(n);
        vector<int> in(n,0);
        for(auto vec:edg){
            edges[vec[0]].push_back(vec[1]);
            in[vec[1]]++;
        }
        queue<int> q;
        vector<int> vis(n,0);
        // Taking set will avoid duplicates
        vector<set<int>> ans(n);
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front(); 
            q.pop();
            for(auto next:edges[node]){
                in[next]--;
                if(in[next]==0){
                    q.push(next);
                }
                // Because current node acts as an ancestor to next node
                ans[next].insert(node);
                // All the ancestors of current node will become ancestors to next node also
                for(auto el:ans[node]){
                    ans[next].insert(el);
                }
            }
        }
        // Pusing set elements back into vector from node 0 to n-1
        vector<vector<int>> res(n);
        for(int i=0;i<n;i++){
            for(auto el:ans[i]){
                res[i].push_back(el);
            }
        }
        return res;
    }
};