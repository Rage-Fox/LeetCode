class Solution {
public:
    int helper(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for (int num : nums) {
            int newRob = max(rob1 + num, rob2);
            rob1 = rob2;
            rob2 = newRob;
        }
        return rob2;
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        // Because of the circular setup, you cannot rob both the first and last
        // house So skip first house in nums1, skip last house in nums2
        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin(), nums.end() - 1);
        return max(helper(nums1), helper(nums2));
    }
};