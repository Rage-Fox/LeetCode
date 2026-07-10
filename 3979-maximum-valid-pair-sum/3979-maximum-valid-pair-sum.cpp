class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int ans = 0;
        int best = nums[0];
        for (int j = k; j < nums.size(); j++) {
            best = max(best, nums[j - k]);
            ans = max(ans, best + nums[j]);
        }
        return ans;
    }
};