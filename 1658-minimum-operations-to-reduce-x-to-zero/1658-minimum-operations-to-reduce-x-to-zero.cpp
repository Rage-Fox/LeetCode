class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(begin(nums), end(nums), 0);
        int reqSum = totalSum - x;
        if (reqSum < 0)
            return -1;
        if (reqSum == 0)
            return nums.size();
        int sum = 0, start = 0, end = 0, res = 0, n = nums.size();
        // we just have to find the largest window with sum equal to
        // (totalSum-x)
        while (end < nums.size()) {
            sum += nums[end];
            while (sum > reqSum) {
                sum -= nums[start];
                start++;
            }
            if (sum == reqSum) {
                res = max(res, end - start + 1);
            }
            end++;
        }
        return res == 0 ? -1 : n - res;
    }
};