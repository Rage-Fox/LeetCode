class Solution {
public:
    vector<vector<int>> adj;
    vector<long long> dp;
    long long dfs(int u, vector<int>& op, vector<int>& score) {
        long long total = score[u], mini = LLONG_MAX;
        for (auto v : adj[u]) {
            long long child = dfs(v, op, score);
            total += child;
            mini = min(mini, child);
        }
        if (adj[u].empty()) {
            return dp[u] = total;
        }
        if (op[u] == 1) {
            total -= mini;
        } else if (mini < 0) {
            total -= mini;
        }
        return dp[u] = total;
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        adj.resize(n);
        dp.resize(n);
        for (int i = n - 1; i > 0; i--) {
            int indx = parent[i];
            adj[indx].push_back(i);
        }
        return dfs(0, op, score);
    }
};