class Solution {
public:
    int cnt=0;
    void dfs(int node, vector<vector<int>>& adj, int k, int val, vector<bool>& vis){
        vis[node] = true;
        if(val > k)
            return ;
        cnt++;
        for(auto it : adj[node]){
            if(!vis[it])
                dfs(it, adj, k, val + 1, vis);
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> ans(n);
        vector<vector<int>> adj1(n), adj2(m);
        for(auto it : edges1){
            int x = it[0], y = it[1];
            adj1[x].push_back(y);
            adj1[y].push_back(x);
        }
        for(auto it : edges2){
            int x = it[0], y = it[1];
            adj2[x].push_back(y);
            adj2[y].push_back(x);
        }
        int maxi = 0;
        for(int i = 0 ; i < m ; i++){
            cnt = 0;
            vector<bool> vis(m);
            dfs(i, adj2, k - 1, 0, vis);
            maxi = max(maxi, cnt);
        }
        for(int i = 0 ; i < n ; i++){
            cnt = 0;
            vector<bool> vis(n);
            dfs(i, adj1, k, 0, vis);
            ans[i] = cnt + maxi;
        }
        return ans;
    }
};