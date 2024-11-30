class Solution {
public:
    vector<vector<int>> ans;
    void dfs(unordered_map<int,vector<int>> &graph,int curr){
        while(!graph[curr].empty()){
            int next=graph[curr].back();
            graph[curr].pop_back();
            dfs(graph,next);
            ans.push_back({curr,next});
        }
        return;
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int m=pairs.size();
        unordered_map<int,vector<int>> graph;
        unordered_map<int,int> out_deg;
        for(auto x:pairs){
            graph[x[0]].push_back(x[1]);
            out_deg[x[0]]++;
            out_deg[x[1]]--;
        }
        int start=pairs[0][0];
        for(auto x:out_deg){
            if(x.second>0){
                start=x.first;
                break;
            }
        }
        dfs(graph,start);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};