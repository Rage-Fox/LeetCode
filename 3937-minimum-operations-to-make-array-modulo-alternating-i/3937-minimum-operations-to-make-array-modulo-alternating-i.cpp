class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y)
                    continue;
                int cost = 0;
                for (int l = 0; l < nums.size(); l++) {
                    int rem = nums[l] % k;
                    if (l % 2 == 0) {
                        // because we can either add 1 or subtract 1 to reach number
                        cost += min((x - rem + k) % k, (rem - x + k) % k);
                    } else {
                        cost += min((y - rem + k) % k, (rem - y + k) % k);
                    }
                }
                ans = min(ans, cost);
            }
        }
        return ans;
    }
};