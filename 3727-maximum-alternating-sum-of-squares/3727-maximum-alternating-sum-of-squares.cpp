class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> x(n, 0);
        for (int i = 0; i < n; i++) {
            x[i] = 1LL * nums[i] * nums[i];
        }
        sort(x.begin(), x.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2)
                ans -= x[i];
            else
                ans += x[i];
        }
        return ans;
    }
};