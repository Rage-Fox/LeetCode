class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> res;
        int sum = 0;
        for (auto it : nums) {
            res.push_back(sum);
            sum += it;
        }
        sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] = abs(res[i] - sum);
            sum += nums[i];
        }
        return res;
    }
};