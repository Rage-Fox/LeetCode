class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MAXX = 50001;
        set<int> obstacles;
        map<int, set<int>> gaps;
        vector<bool> ans;
        // Initially one huge gap: [0, MAXX]
        obstacles.insert(0);
        obstacles.insert(MAXX);
        gaps[MAXX].insert(0);
        for (auto& q : queries) {
            // Add obstacle
            if (q[0] == 1) {
                int pos = q[1];
                auto right = obstacles.lower_bound(pos);
                auto left = prev(right);
                int L = *left;
                int R = *right;
                // Remove old gap [L, R]
                gaps[R - L].erase(L);
                if (gaps[R - L].empty())
                    gaps.erase(R - L);
                // Add new gaps [L, pos] and [pos, R]
                gaps[pos - L].insert(L);
                gaps[R - pos].insert(pos);
                obstacles.insert(pos);
            } else {
                int x = q[1];
                int sz = q[2];
                bool possible = false;
                // Check all gaps having length >= sz
                auto it = gaps.lower_bound(sz);
                while (it != gaps.end()) {
                    int gapLength = it->first;
                    // Earliest starting position of this gap length
                    // If the smallest start already fails, every larger start fails too
                    int start = *it->second.begin();
                    // Can a block of size sz start here and stay within [0, x]?
                    if (start + sz <= x) {
                        possible = true;
                        break;
                    }
                    it++;
                }
                ans.push_back(possible);
            }
        }
        return ans;
    }
};