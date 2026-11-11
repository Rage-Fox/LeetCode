class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Euler path - Visit every edge exactly once
        // Hierholzer's Algorithm (Iteration Mode)
        unordered_map<string, vector<string>> adj;
        for (const auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        // Reverse Lexicographical Order - Pop smaller from back
        for (auto& [src, destinations] : adj) {
            sort(destinations.rbegin(), destinations.rend());
        }
        vector<string> res;
        stack<string> stk;
        stk.push("JFK");
        while (!stk.empty()) {
            string curr = stk.top();
            if (adj[curr].empty()) {
                res.push_back(curr);
                stk.pop();
            } else {
                string next = adj[curr].back();
                adj[curr].pop_back();
                stk.push(next);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};