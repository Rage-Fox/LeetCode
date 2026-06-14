class Solution {
public:
    vector<int> parent;
    int findUltimateParent(int x) {
        int p = parent[x];
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    void unionGraph(int x, int y) {
        int a = findUltimateParent(x);
        int b = findUltimateParent(y);
        parent[b] = parent[a];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(edges.size() + 1);
        int ind = -1;
        for (int i = 0; i <= edges.size(); i++) {
            parent[i] = i;
        }
        for (int i = 0; i < edges.size(); i++) {
            if (findUltimateParent(edges[i][0]) != findUltimateParent(edges[i][1])) {
                // connect and form a graph if ultimate parents are not same
                unionGraph(edges[i][0], edges[i][1]);
            }
            else {
                ind = i;
            }
        }
        return edges[ind];
    }
};