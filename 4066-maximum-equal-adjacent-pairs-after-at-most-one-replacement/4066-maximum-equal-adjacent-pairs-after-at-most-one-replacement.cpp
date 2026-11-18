class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int, int>, int> mpp;
        int adj = 0, mx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                adj++;
            else {
                // i-1 or i anything is replaceable
                mpp[{nums[i], nums[i - 1]}]++;
                mpp[{nums[i - 1], nums[i]}]++;
            }
        }
        for (auto it : mpp)
            mx = max(mx, it.second);
        return adj + mx;
    }
};