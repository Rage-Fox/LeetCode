class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> count, res;
        for (int x : planks) {
            count[x]++;
            res[x]++;
        }
        for (auto &pair_a : count) {
            for (auto &pair_b : count) {
                int a = pair_a.first, b = pair_b.first;
                if (a < b) {
                    res[a + b] += min(pair_a.second, pair_b.second);
                }
                if (a == b) {
                    res[a + b] += pair_a.second / 2;
                }
            }
        }
        int max_val = 0;
        for (auto const& pair : res) {
            max_val = max(max_val, pair.second);
        }
        return max_val;
    }
};