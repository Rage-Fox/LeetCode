class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int l = i > 0 ? nums[i - 1] : nums[i];
            int r = i < n - 1 ? nums[i + 1] : nums[i];
            float avg = (l + r) / 2.0;
            if (nums[i] >= avg)
                res++;
        }
        return res;
    }
};