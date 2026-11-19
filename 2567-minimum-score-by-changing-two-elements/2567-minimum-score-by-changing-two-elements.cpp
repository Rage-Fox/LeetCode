class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3)
            return 0;
        sort(nums.begin(), nums.end());
        int low = 0; // always 0, will make some element equal
        int high = min({nums[n - 1] - nums[2],   // changed smaller values
                        nums[n - 3] - nums[0],   // changed big values
                        nums[n - 2] - nums[1]}); // one big, one small
        return low + high;
    }
};