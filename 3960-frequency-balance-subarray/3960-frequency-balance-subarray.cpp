class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            unordered_map<int, int> cnt;
            for (int j = i; j < n; j++) {
                int x = nums[j];
                int old = freq[x];
                if (old) {
                    cnt[old]--;
                    if (cnt[old] == 0)
                        cnt.erase(old);
                }
                freq[x]++;
                cnt[old + 1]++;
                int len = j - i + 1;
                int mn = INT_MAX;
                int mx = INT_MIN;
                bool ok = false;
                if (freq.size() == 1) {
                    ans = max(len, ans);
                } else if (cnt.size() == 2) {
                    auto it = cnt.begin();
                    int f1 = it->first;
                    ++it;
                    int f2 = it->first;
                    int mn = min(f1, f2);
                    int mx = max(f1, f2);
                    if (mx == 2 * mn)
                        ok = true;
                }
                if (ok)
                    ans = max(ans, len);
            }
        }
        return ans;
    }
};