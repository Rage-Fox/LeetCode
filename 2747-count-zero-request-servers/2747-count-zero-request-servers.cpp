class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto& a, auto& b) {
                return a[1] < b[1];
        });
        vector<pair<int, int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        vector<int> ans(queries.size());
        unordered_map<int, int> mp;
        int active = 0, start = 0, end = 0;
        for (auto& it : q) {
            int high = it.first;
            int low = high - x;
            int idx = it.second;
            while (end < logs.size() && logs[end][1] <= high) {
                int server = logs[end][0];
                if (mp[server] == 0)
                    active++;
                mp[server]++;
                end++;
            }
            // removing old logs with start pointer that doesn't fall in current query range
            while (start < logs.size() && logs[start][1] < low) {
                int server = logs[start][0];
                mp[server]--;
                if (mp[server] == 0)
                    active--;
                start++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};