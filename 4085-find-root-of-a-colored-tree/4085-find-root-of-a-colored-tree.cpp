class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.length();
        vector<int> inDegree(n), outDegree(n);
        unordered_map<char, char> map = {{'R', 'B'}, {'B', 'W'}, {'W', 'R'}};
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (colors[u] == colors[v])
                return -1;
            else if (map[colors[u]] == colors[v]) {
                inDegree[v]++;
                outDegree[u]++;
            } else {
                inDegree[u]++;
                outDegree[v]++;
            }
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (outDegree[i] > 2 || inDegree[i] > 1)
                return -1;
            if (inDegree[i] == 0) {
                if (root != -1)
                    return -1;
                root = i;
            }
        }
        return root;
    }
};