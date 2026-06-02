class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        long long dp1 = 0, dp2 = nums[0], next_dp2;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                next_dp2 = max(dp2, dp1 + nums[i]);
            } else {
                next_dp2 = dp2 + nums[i];
            }
            dp1 = dp2;
            dp2 = next_dp2;
        }
        return dp2;
    }
};