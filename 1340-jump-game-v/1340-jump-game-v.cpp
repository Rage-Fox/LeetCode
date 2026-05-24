class Solution {
public:
    int solve(vector<int>& nums, int d, int i, vector<int>& dp) {
        if (dp[i] != -1) {
            return dp[i];
        }
        int cnt = 1;
        for (int jump = i - 1; jump >= 0 && i - jump <= d; jump--) {
            if (nums[i] > nums[jump]) {
                cnt = max(cnt, 1 + solve(nums, d, jump, dp));
            } else {
                break;
            }
        }
        for (int jump = i + 1; jump < nums.size() && jump - i <= d; jump++) {
            if (nums[i] > nums[jump]) {
                cnt = max(cnt, 1 + solve(nums, d, jump, dp));
            } else {
                break;
            }
        }
        return dp[i] = cnt;
    }
    int maxJumps(vector<int>& arr, int d) {
        vector<int> dp(arr.size(), -1);
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            ans = max(ans, solve(arr, d, i, dp));
        }
        return ans;
    }
};