class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            int ans = 0;
            int x = nums[i];
            while (x != 0) {
                ans += x % 10;
                x /= 10;
            }
            v.push_back({nums[i], ans});
            m[nums[i]] = i;
        }
        sort(v.begin(), v.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.second == b.second)
                     return a.first < b.first;
                 return a.second < b.second;
             });
        int res = 0;
        for (int i = 0; i < n; i++) {
            // If the number is already in the correct position, skip
            if (nums[i] != v[i].first) {
                // Find the index where the required number is currently placed
                int ind = m[v[i].first];
                swap(nums[i], nums[ind]);
                m[nums[i]] = i;
                m[nums[ind]] = ind;
                res++;
            }
        }
        return res;
    }
};