class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [](const auto& a, const auto& b) {
                 return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
             });
        vector<int> tails;
        for (auto& e : envelopes) {
            auto it = lower_bound(tails.begin(), tails.end(), e[1]); // height
            if (it == tails.end())
                tails.push_back(e[1]);
            else
                *it = e[1];
        }
        return (int)tails.size();
    }
};